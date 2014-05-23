#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int a=9999;

int main(){
    char filename[100];
    int fd;
    int data=888;

    sprintf(filename,"/proc/%d/mem",getpid());

    fd=open(filename,O_RDWR);
    if(fd==-1){printf("open error:%m\n");exit(-1);}
    
    printf("%p\n",&a);

    //pread(fd,&data,4,(int)&a);
    lseek(fd,(int)&a,SEEK_SET);
    //read(fd,&data,4);
    write(fd,&data,4);
    //pwrite(fd,&data,4,(int)&a);

    printf("%d\n",a);
}
