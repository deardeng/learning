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

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)

//#define ERR_EXIT(m) (perror(m),exit(EXIT_FAILURE))

int main(int argc,char *argv[]){
    int fd;
    fd = open("test2.txt",O_WRONLY);
    if(fd == -1)
        ERR_EXIT("open error");

    //close(1);
    //dup(fd);
    dup2(fd,1);
    printf("hello\n");

    return 0;
}
