#include<iostream>
using namespace std;
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<string>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

void func(int sig){
    signal(sig,func);
    wait(NULL);
}

int main(int argc,char *argv[]){
    signal(SIGCHLD,func);
    short port=12345;
    if(argc>1)
        port=atoi(argv[1]);
    int ss=socket(AF_INET,SOCK_STREAM,0);
    if(ss<0)return -1;
    sockaddr_in si;
    si.sin_family=AF_INET;
    si.sin_port=htons(port);
    si.sin_addr.s_addr=0;
    socklen_t len=sizeof(si);
    int r=bind(ss,(sockaddr *)&si,len);
    if(r<0)return -2;
    r=listen(ss,20);
    if(r<0)return -3;
    sockaddr_in c;
    cout << "listen on" << port << endl;
    for(;;){
        len=sizeof(c);
        int cs=accept(ss,(sockaddr *)&c,&len);
        if(cs<0)continue;
        if(fork()!=0){//parent process
            close(cs);
            continue;
        }
        //child process
        close(ss);
        char ip[100];
        inet_ntop(AF_INET,&c.sin_addr.s_addr,ip,sizeof(ip));
        cout << ip << ": Come Here !" << endl;
        string msg="Your ip:";
        msg+=ip;
        msg+='\n';
        write(cs,msg.c_str(),msg.size());
        char buf[1000];
        for(;;){
            //read from client
            int n=read(cs,buf,1000);
            if(n<=0)break;
            buf[n] = '\0';
            msg=ip;
            msg+=':';
            msg+=buf;
            cout << msg << endl;
            //write to client
            msg="server:";
            msg+=buf;
            write(cs,msg.c_str(),msg.size());
            if(buf[0]=='q')break;
        }
        close(cs);
        cout << ip << "exited." << endl;
        exit(0);//end child process
    }
    return 0;
}
