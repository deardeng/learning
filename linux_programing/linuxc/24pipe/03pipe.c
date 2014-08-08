#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)

void handler(int sig){
    printf("recv a sig = %d\n",sig);
}

int main(int argc,char *argv[]){
    signal(SIGPIPE,handler);
    int pipefd[2];
    if(pipe(pipefd) == -1)
        ERR_EXIT("pipe error");

    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERR_EXIT("fork error");

    if(pid == 0){
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }

    close(pipefd[0]);
    sleep(1);
    int ret = write(pipefd[1],"hello",5);
    if(ret == -1)
        printf("write error!\n");
    return 0;
}
