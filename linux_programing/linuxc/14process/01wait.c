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



int main(int argc,char *argv[]){
    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERR_EXIT("fork error");
    if(pid == 0){
        sleep(3);
        printf("this is child\n");
        //exit(100);
        abort();
    }
    int ret; printf("this is parent\n");
    int status;
    //ret = wait(&status);
    //ret = waitpid(-1,&status,0);
    ret = waitpid(pid,&status,0);
    printf("ret = %d pid = %d\n",ret,pid);
    if(WIFEXITED(status))
        printf("child exited normal exit status = %d\n", WEXITSTATUS(status));
    /*else
        printf("child exited abnormal\n");
    */
    else if(WIFSIGNALED(status))
        printf("child exited abnormal signal number = %d\n",WTERMSIG(status));
    else if(WIFSTOPPED(status))
        printf("child stoped signal number = %d\n",WSTOPSIG(status));
    return 0;
}
