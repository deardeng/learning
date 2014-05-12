#include<iostream>
using namespace std;
#include<unistd.h>
#include<stdlib.h>

int main(){
    if(fork()==0){
        char *argv[5]={
            "cmdlind",
            "aa","bb","cc",
            NULL
        };
        execvp("cmdline",argv);
        cout << "Not found cmdline!" << endl;
        return -1;
    }
    else{
        sleep(10);
    }
}
