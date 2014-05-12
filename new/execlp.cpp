#include<iostream>
using namespace std;
#include<unistd.h>
#include<stdlib.h>

int main(){
    if(fork()==0){
        execlp("cmdline","cmdlind","aa","bb","cc",NULL);
        cout << "Not found cmdline!" << endl;
        return -1;
    }
    else{
        sleep(10);
    }
}
