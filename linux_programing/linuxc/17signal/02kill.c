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
    if(signal(SIGUSR1,handler)== SIG_ERR)
        ERR_EXIT("signal error");
    pid_t pid = fork();
    if(pid == -1)
        ERR_EXIT("fork error");
    if(pid == 0){
        //pid = getpgrp();
        //kill(-pid,SIGUSR1);
        killpg(getpgrp(),SIGUSR1);
        exit(EXIT_SUCCESS);
    }
    int n;
    do{
        n=sleep(5);
    }while(n>0);
    return 0;
}

void handler(int sig){
    printf("recv a sig = %d\n",sig);
}
