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

int setup_daemon(int nochdir,int noclose);

int main(int argc,char *argv[]){
    setup_daemon(0,0);
    printf("test...\n");
    for(;;);
    return 0;
}

int setup_daemon(int nochdir,int noclose){
    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERR_EXIT("fork error");
    if(pid > 0)
        exit(EXIT_SUCCESS);

    setsid();
    if(nochdir == 0)
        chdir("/");
    if(noclose == 0){
        int i;
        for(i=0;i<3;++i)
            close(i);
        open("/dev/null",O_RDWR);
        dup(0);
        dup(0);
    }
    return 0;
}
