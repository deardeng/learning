#include<iostream>
using namespace std;
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    if(fork()==0){//child process
        for(int i=0;i<5;i++){
            cout << "child:" << getpid() << endl;
            sleep(1);
        }
        cout << "---child end---" << endl;
        return 123;
    }
    else{

        cout << "parent:" << getpid() << endl;
        pid_t cid=wait(NULL);
        cout << "wait " << cid << endl;
        cout << "sleep 10" << endl;
        sleep(10);
        return 0;
    }
    return 0;
}
