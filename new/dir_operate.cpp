#include<iostream>
using namespace std;
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(){
    string cmd;
    string name;
    for(;;){
        cout << "cmd:";
        cin >> cmd;
        if(cmd=="mkdir"){
            cin >> name;
            mkdir(name.c_str(),0777);
        }
        else if(cmd=="rmdir"){
            cin >> name;
            rmdir(name.c_str());
        }
        else if(cmd=="chdir"){
            cin >> name;
            chdir(name.c_str());
        }
        else if(cmd=="pwd"){
            char buf[256];
            getcwd(buf,256);
            cout << buf << endl;
        }
        else if(cmd=="buy"){
            cout << "C U" << endl;
        }
        else
            cout << "unkown command!" << endl;
    }
}
