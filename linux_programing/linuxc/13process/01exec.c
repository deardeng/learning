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

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)



int main(int argc,char *argv[]){
    printf("Enter main...\n");
    printf("pid = %d\n",getpid());
    //execlp("./hello","hello",NULL);
    int ret=execlp("hello","hello",NULL);
    if(ret == -1)
        perror("execlp error:");
    printf("Exiting main...\n");
    return 0;
}
