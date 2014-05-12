#include<iostream>
using namespace std;
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

struct Msg{
    long tongdao;
    char name[20];
    int age;
};

int main(int argc,char *argv[]){
    if(argc==1){
        cout << *argv << " key" << endl;
        return 0;
    }
    int key=atoi(argv[1]);
    int qid;
    qid=msgget(key,IPC_CREAT|0600);
    if(qid<0){
        cout << "cannot creat" << endl;
        return -1;
    }
    cout << "OK!" << endl;
    cout << "key=0x" << hex << key << endl;
    cout << "qid=" << dec << qid << endl;
    Msg m;
    cout << "input tongdao num: ";
    int no;
    cin >> no;
    msgrcv(qid,&m,sizeof(Msg),no,0);
    cout << m.tongdao << endl;
    cout << m.name << endl;
    cout << m.age << endl;
}
