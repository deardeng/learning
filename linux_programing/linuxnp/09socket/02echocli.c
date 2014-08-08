#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)



struct packet{
    int len;
    char buf[1024];
};

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

int main(int argc, const char *argv[])
{
    int sock;
    if((sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0)
        ERR_EXIT("socket");
    //listenfd = socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //inet_aton("127.0.0.1",&servaddr.sin_addr);

    if(connect(sock,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
        ERR_EXIT("connect");

    struct packet sendbuf;
    struct packet recvbuf;
    memset(&sendbuf,0,sizeof(sendbuf));
    memset(&recvbuf,0,sizeof(recvbuf));
    int n;

    while(fgets(sendbuf.buf,sizeof(sendbuf.buf),stdin)!=NULL){
        n = strlen(sendbuf.buf);
        sendbuf.len = htonl(n);
        writen(sock,&sendbuf,4+n);

        int ret = readn(sock,&recvbuf.len,4);
        if(ret == -1)
            ERR_EXIT("read");
        else if(ret < 4){
            printf("client close\n");
            break;
        }
        n = ntohl(recvbuf.len);
        ret = readn(sock,recvbuf.buf,n);
        if(ret == -1)
            ERR_EXIT("read");
        else if(ret < n){
            printf("client close\n");
            break;
        }

        fputs(recvbuf.buf,stdout);
        memset(&sendbuf,0,sizeof(sendbuf));
        memset(&recvbuf,0,sizeof(recvbuf));
    }
    close(sock);
    return 0;
}
