#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "execute.h"
#include "parse.h"
#include "externs.h"
#include "init.h"
#include "execute.h"

void forkexec(int i){
    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERR_EXIT("fork");

    if(pid > 0){
        if(backgnd == 1)
            printf("%d\n",pid);
        lastpid = pid;
    }
    else if(pid == 0){
        if(cmd[i].infd == 0 && backgnd == 1){
            cmd[i].infd = open("/dev/null",O_RDONLY);
            //printf("infd = %d\n",cmd[i].infd);
        }
        if(i==0){
            setpgid(0,0);
        }

        if(cmd[i].infd!=0){
            close(0);
            dup(cmd[i].infd);
        }
        if(cmd[i].outfd!=1){
            close(1);
            dup(cmd[i].outfd);
        }
        //for(i=3;i<OPEN_MAX;++i)
        int j;
        for(j=3;j<1024;++j)
            close(j);
        if(backgnd == 0){
            signal(SIGINT,SIG_DFL);
            signal(SIGQUIT,SIG_DFL);
        }
        execvp(cmd[i].args[0],cmd[i].args);
        exit(EXIT_FAILURE);
    }
}

int execute_disk_command(void){
    //pid_t pid = fork();
    //if(pid == -1)
    //    ERR_EXIT("fork");
    //if(pid == 0){
    //    execvp(cmd.args[0],cmd.args);
    //}
    //wait(NULL);

    //if(cmd_count == 0)
    //    return 0;

    if(cmd_count == 0)
        return 0;


    if(infile[0] != '\0')
        cmd[0].infd = open(infile,O_RDONLY);
    if(outfile[0] != '\0'){
        if(append)
            cmd[cmd_count -1].outfd = open(outfile,O_WRONLY | O_CREAT | O_APPEND, 0666);
        else
            cmd[cmd_count -1].outfd = open(outfile,O_WRONLY | O_CREAT | O_TRUNC, 0666);
    }
    if(backgnd == 1){
        signal(SIGCHLD,SIG_IGN);
    }
    else
        signal(SIGCHLD,SIG_DFL);

    int i;
    int fd;
    int fds[2];
    for(i=0;i<cmd_count;++i){
        if(i<cmd_count-1){
            pipe(fds);
            cmd[i].outfd = fds[1];
            cmd[i+1].infd = fds[0];
        }
        forkexec(i);

        if((fd = cmd[i].infd)!= 0)
            close(fd);
        if((fd = cmd[i].outfd)!= 1)
            close(fd);
    }
    if(backgnd == 0){
        while(wait(NULL) != lastpid);
    }

    return 0;
}
