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
    int pipefd[2];
    if(pipe(pipefd) == -1)
        ERR_EXIT("pipe error");

    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERR_EXIT("fork error");

    if(pid == 0){
        close(pipefd[1]);
        write(pipefd[1],"hello",5);
        exit(EXIT_SUCCESS);
    }

    close(pipefd[1]);
    sleep(1);
    char buf[10]={0};
    int ret = read(pipefd[0],buf,10);
    printf("ret = %d\n",ret);
    return 0;
}
