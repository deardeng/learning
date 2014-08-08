#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <poll.h>

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)

ssize_t readn(int fd, void *buf, size_t count){
    size_t nleft = count;
    ssize_t nread;
    char *bufp = (char*)buf;

    while(nleft > 0){
        if((nread = read(fd,bufp,nleft))<0){
            if(errno == EINTR)
                continue;
            return -1;
        }
        else if(nread == 0)
            return count - nleft;

        bufp += nread;
        nleft -= nread;
    }
    return count;
}

ssize_t writen(int fd, const void *buf, size_t count){
    size_t nleft = count;
    ssize_t nwritten;
    char *bufp = (char*)buf;

    while(nleft > 0){
        if((nwritten = write(fd,bufp,nleft))<0){
            if(errno == EINTR)
                continue;
            return -1;
        }
        else if(nwritten == 0)
            continue;
        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}

ssize_t recv_peek(int sockfd, void *buf, size_t len){
    while(1){
        int ret = recv(sockfd,buf,len,MSG_PEEK);
        if(ret == -1 && errno == EINTR)
            continue;
        return ret;
    }
}
ssize_t readline(int sockfd, void *buf, size_t maxline){
    int ret;
    int nread;
    char *bufp = (char*)buf;
    int nleft = maxline;
    while(1){
        ret = recv_peek(sockfd,bufp,nleft);
        if(ret < 0)
            return ret;
        else if(ret == 0)
            return ret;
        nread = ret;
        int i;
        for(i=0;i<nread;i++){
            if(bufp[i] == '\n'){
                ret = readn(sockfd,bufp,i+1);
                if(ret != i+1)
                    exit(EXIT_FAILURE);
                return ret;
            }
        }
        if(nread > nleft)
            exit(EXIT_FAILURE);

        nleft -= nread;
        ret = readn(sockfd,bufp,nread);
        if(ret != nread)
            exit(EXIT_FAILURE);
        bufp += nread;
    }
    return -1;
}

void echo_srv(int conn){
    char recvbuf[1024];
    while(1){
        memset(&recvbuf,0,sizeof(recvbuf));
        int ret = readline(conn,recvbuf,sizeof(recvbuf));
        if(ret == -1)
            ERR_EXIT("readline");
        if(ret == 0){
            printf("client close\n");
            break;
        }
        fputs(recvbuf,stdout);
        writen(conn,recvbuf,strlen(recvbuf));
    }
}
void handle_sigchld(int sig){
    //wait(NULL);
    while(waitpid(-1,NULL,WNOHANG)>0);
}

void handle_sigpipe(int sig){
    //wait(NULL);
    printf("recv a sig = %d\n",sig);
}
int main(int argc, const char *argv[])
{
    int count = 0;
    //signal(SIGCHLD,SIG_IGN);
    signal(SIGCHLD,handle_sigchld);
    signal(SIGPIPE,handle_sigpipe);
    int listenfd;
    if((listenfd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0)
        ERR_EXIT("socket");
    //listenfd = socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //inet_aton("127.0.0.1",&servaddr.sin_addr);

    int on = 1;
    if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
        ERR_EXIT("SETSOCKOPT");
    if(bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0)
        ERR_EXIT("bind");

    if(listen(listenfd,SOMAXCONN) < 0)
        ERR_EXIT("listen");

    struct sockaddr_in peeraddr;
    socklen_t peerlen;
    int conn;
    //pid_t pid;
    //while(1){

    //    if((conn = accept(listenfd,(struct sockaddr*)&peeraddr,&peerlen)) < 0)
    //        ERR_EXIT("accept");
    //    printf("ip = %s port = %d\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));

    //    pid = fork();
    //    if(pid == -1)
    //        ERR_EXIT("fork");
    //    if(pid == 0){
    //        close(listenfd);
    //        echo_srv(conn);
    //        exit(EXIT_SUCCESS);
    //    }
    //    else
    //        close(conn);
    //}

    int i;
    struct pollfd client[2048];
    int maxi = 0;

    for(i=0;i<2048;++i)
        client[i].fd = -1;

    int nready;
    client[0].fd = listenfd;
    client[0].events = POLLIN;

    while(1){
        nready = poll(client,maxi+1,-1);
        if(nready == -1){
            if(errno == EINTR)
                continue;
            ERR_EXIT("poll");
        }
        if(nready == 0)
            continue;

        if(client[0].revents & POLLIN){
            peerlen = sizeof(peeraddr);
            conn = accept(listenfd,(struct sockaddr*)&peeraddr,&peerlen);
            if(conn == -1)
                ERR_EXIT("accept");

            for(i=0;i<2048;++i){
                if(client[i].fd<0){
                    client[i].fd = conn;
                    if(i > maxi)
                        maxi = i;
                    break;
                }
            }

            if(i == 2048){
                fprintf(stderr,"too many clients\n");
                exit(EXIT_FAILURE);
            }
            printf("ip = %s port = %d\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));
            printf("count = %d\n",++count);

            client[i].events = POLLIN;

            if(--nready <= 0)
                continue;
        }
        for(i=1;i<=maxi;++i){
            conn = client[i].fd;
            if(conn == -1)
                continue;

            if(client[i].events & POLLIN){
                char recvbuf[1024] = {0};
                int ret = readline(conn,recvbuf,sizeof(recvbuf));
                if(ret == -1)
                    ERR_EXIT("readline");
                if(ret == 0){
                    printf("client close\n");
                    client[i].fd = -1;
                    close(conn);
                }
                fputs(recvbuf,stdout);
                writen(conn,recvbuf,strlen(recvbuf));

                if(--nready <= 0)
                    break;
            }
        }
    }
    return 0;
}
