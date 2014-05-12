#include<iostream>
using namespace std;
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>

void func(int sig){
    signal(sig,func);
    wait(NULL);
    cout << "waited one child" << endl;
}
void child(int len,char ch){
    if(fork()!=0)
        return;
    for(int i=0;i<len;i++){
        cerr << ch;
        sleep(3);
    }
    exit(0);
}

int main(){
    signal(SIGCHLD,func);
    child(10,'.');
    child(20,'^');
    for(int i=0;i<100;i++){
        cerr << '$';
        sleep(1);
    }
}
