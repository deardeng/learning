#include<iostream>
using namespace std;
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    if(argc!=3){
        cout << *argv << " ip port " << endl;
        return 0;
    }
    int s=socket(AF_INET,SOCK_STREAM,0);
    if(s<0)return -1;
    sockaddr_in si;
    short port=atoi(argv[2]);
    char *ip=argv[1];
    si.sin_family=AF_INET;
    si.sin_port=htons(port);
    inet_pton(AF_INET,ip,&si.sin_addr.s_addr);
    int r=connect(s,(sockaddr *)&si,sizeof(si));
    if(r<0)return -1;
    char msg[200];
    int n=read(s,msg,sizeof(msg));
    if(n<0)return -2;
    msg[n]='\0';
    cout << msg << endl;
    for(;;){
        cout << "msg:";
        cin.getline(msg,200);
        if(msg[0]=='q')break;
        //write message to server
        n=write(s,msg,strlen(msg));
        if(n<=0)break;
        //read echo from server
        n=read(s,msg,sizeof(msg));
        if(n<=0)break;
        msg[n]='\0';
        cout << msg << endl;
    }
    close(s);
}
