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


int main(int argc,char *argv[]){
    int fd;
    fd = open("hole.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd == -1)
        ERR_EXIT("open error");

    write(fd,"ABCDE",5);

    int ret = lseek(fd,32,SEEK_CUR);
    if(ret == -1)
        ERR_EXIT("lseek error");

    write(fd,"hello",5);

    return 0;
}
