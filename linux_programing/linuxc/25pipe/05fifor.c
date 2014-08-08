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
    int outfd;
    outfd = open("makefile2",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(outfd == -1)
        ERR_EXIT("open");

    int infd;
    infd = open("tp",O_RDONLY);
    if(infd == -1)
        ERR_EXIT("open");

    char buf[1024];
    int n;
    while((n=read(infd,buf,1024))>0){
        write(outfd,buf,n);
    }
    close(infd);
    close(outfd);
    unlink("tp");
    return 0;
}
