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

int main(int argc,char *argv[]){
    mkfifo("tp",0644);
    int infd;
    infd = open("makefile",O_RDONLY);
    if(infd == -1)
        ERR_EXIT("open");

    int outfd;
    outfd = open("tp",O_WRONLY);
    if(outfd == -1)
        ERR_EXIT("open");

    char buf[1024];
    int n;
    while((n=read(infd,buf,1024))>0){
        write(outfd,buf,n);
    }
    close(infd);
    close(outfd);
    return 0;
}
