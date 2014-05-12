#include<iostream>
using namespace std;
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
void make_daemon();
void work();

int main(){
    make_daemon();
}

void make_daemon(){
    if(fork()!=0)
        exit(0);
    setsid();
    umask(0077);
    for(int fd=0;fd<256;fd++)
        close(fd);
    work();
}

void work(){
    char ch='A';
    for(;;){
        int fd=open("tick.txt",O_WRONLY|O_CREAT|O_APPEND,0777);
        if(fd>=0){
            write(fd,&ch,1);
            close(fd);
        }
        ch++;
        if(ch>'Z')
            ch='A';
        sleep(3);
    }
}
