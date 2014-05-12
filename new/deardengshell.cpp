#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>

int main(){
    cout << "welcome to use deardengshell!" << endl;
    for(;;){
        string cmd;
        cout << "DDS> ";
        getline(cin,cmd);
        if(cmd=="exit")break;
        system(cmd.c_str());
    }
    cout << "thanks for using!" << endl;
    return 0;
}
