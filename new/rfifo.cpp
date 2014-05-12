#include<iostream>
using namespace std;
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    mkfifo("a.fifo",0600);
    int fd=open("a.fifo",O_RDONLY);
    if(fd<0){
        cout << "error!" << endl;
        return -1;
    }
    cout << "pipe ready!" << endl;
    for(;;){
        char buf[1000];
        int n;
        n=read(fd,buf,1000);
        buf[n]='\0';
        cout << "info: " << buf << endl;
        if(strcmp(buf,"bye")==0)
            break;
    }
    close(fd);
}
