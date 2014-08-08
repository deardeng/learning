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
    int fd1;
    int fd2;
    char buf1[1024]={0};
    char buf2[1024]={0};
    fd1 = open("test.txt",O_RDONLY);
    if(fd1 == -1)
        ERR_EXIT("open error");
    read(fd1,buf1,5);
    printf("buf1 = %s\n",buf1);

    fd2 = open("test.txt",O_RDWR);
    if(fd1 == -1)
        ERR_EXIT("open error");
    read(fd2,buf2,5);
    printf("buf2 = %s\n",buf2);
    write(fd2,"AAAAA",5);
    memset(buf1,0,sizeof(buf1));
    read(fd1,buf1,5);
    printf("buf1 = %s\n",buf1);
    close(fd1);
    close(fd2);
    return 0;
}
