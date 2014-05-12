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
    if(fork()!=0){
        system("sudo modprobe i8k");
        exit(0);
    }
    setsid();
    umask(0077);
    for(int fd=0;fd<256;fd++)
        close(fd);
    work();
}
void work(){
    for(;;){
        system("i8kfan -f 20000");
        sleep(1);
    }
}
