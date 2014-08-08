#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)

//#define ERR_EXIT(m) (perror(m),exit(EXIT_FAILURE))

int main(void){
    int fd;
    umask(0);
    fd = open("test.txt",O_WRONLY|O_CREAT|O_EXCL,0666);//new = 0666&~umask
    if(fd == -1){
        ERR_EXIT("open error");
    }
    printf("open succ\n");
    return 0;
}
