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
typedef struct{
    int a;
    int b;
}TEST;

TEST g_data;

int main(int argc,char *argv[]){
    TEST zeros = {0,0};
    TEST ones = {1,1};
    if(signal(SIGALRM,handler)== SIG_ERR)
        ERR_EXIT("signal error");
    g_data = zeros;
    alarm(1);
    for(;;){
        g_data = zeros;
        g_data = ones;
    }
    return 0;
}

void unsafe_fun(){
    printf("%d %d\n",g_data.a,g_data.b);
}

void handler(int sig){
    unsafe_fun();
    alarm(1);
}
