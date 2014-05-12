#include<iostream>
using namespace std;
#include<signal.h>
#include<unistd.h>

void func(int sig){
    if(sig==SIGINT)
        cout << "Ctrl+c" << endl;
    else if(sig==SIGUSR1)
        cout << "user signal 1" << endl;
    else if(sig==SIGUSR2)
        cout << "user signal 2" << endl;
    else
        cout << "unknow??" << endl;
}
int main(){
    cout << "=====1=====" << endl;
    signal(SIGINT,func);
    signal(SIGUSR1,func);
    signal(SIGUSR2,func);
    cout << "=====2=====" << endl;
    for(int i=0;i<20;i++){
        sleep(10);
        cerr << '.';
    }
    cout << "=====3=====" << endl;
}
