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
    if(signal(SIGALRM,handler)==SIG_ERR)
        ERR_EXIT("signal error");
    struct timeval tv_interval = {1,0};
    struct timeval tv_value = {5,0};
    struct itimerval it;
    it.it_interval = tv_interval;
    it.it_value = tv_value;
    setitimer(ITIMER_REAL,&it,NULL);

    for(;;)
        pause();
    return 0;
}
