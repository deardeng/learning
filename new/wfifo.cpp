#include<iostream>
using namespace std;
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    mkfifo("a.fifo",0600);
    int fd=open("a.fifo",O_WRONLY);
    if(fd<0){
        cout << "error!" << endl;
        return -1;
    }
    cout << "pipe ready!" << endl;
    for(;;){
        cout << "input text:";
        string str;
        getline(cin,str);
        write(fd,str.c_str(),str.size());
        if(str=="bye")
            break;
    }
    close(fd);
}
