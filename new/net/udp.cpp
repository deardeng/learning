#include<iostream>
using namespace std;
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    short port=12345;
    if(argc>1)
        port=atoi(argv[1]);
    int s=socket(AF_INET,SOCK_DGRAM,0);
    sockaddr_in si;
    si.sin_family=AF_INET;
    si.sin_addr.s_addr=0;
    si.sin_port=htons(port);
    socklen_t len=sizeof(si);
    int r=bind(s,(sockaddr *)&si,len);
    if(r<0)return -1;
    char cmd;
    char ip[100];
    char msg[1000];
    sockaddr_in c;
    len=sizeof(c);
    for(;;){
        cout << "cmd:r/a/s/q " << endl;
        cin >> cmd;
        switch(cmd){
            case 'r':
               r=recvfrom(s,msg,1000,0,(sockaddr *)&c,&len);
               msg[r]='\0';
               port=ntohs(c.sin_port);
               inet_ntop(AF_INET,&c.sin_addr.s_addr,ip,sizeof(ip));
               cout << ip << '@' << port << ':' << msg << endl;
               break;
            case 'a':
               cin.getline(msg,1000);
               sendto(s,msg,strlen(msg),0,(sockaddr *)&c,len);
               break;
            case 's':
               cin >> ip >> port;
               cin.getline(msg,1000);
               c.sin_family=AF_INET;
               c.sin_port=htons(port);
               inet_pton(AF_INET,ip,&c.sin_addr.s_addr);
               sendto(s,msg,strlen(msg),0,(sockaddr *)&c,len);
               break;
            case 'q':
               exit(0);
            default:
               cout << "invalid cmd\n";
               cin.ignore(1000,'\n');
        }
    }
}
