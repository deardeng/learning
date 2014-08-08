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

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)


void handler(int sig);

int main(int argc,char *argv[]){
    __sighandler_t oldhandler;
    oldhandler = signal(SIGINT,handler);
    if(oldhandler == SIG_ERR)
        ERR_EXIT("signal error");
    while(getchar()!= '\n')
        ;
    //if(signal(SIGINT,oldhandler)==SIG_ERR)
    if(signal(SIGINT,SIG_DFL)==SIG_ERR)
        ERR_EXIT("signal error");
    for(;;);
    return 0;
}

void handler(int sig){
    printf("recv a sig = %d\n",sig);
}
