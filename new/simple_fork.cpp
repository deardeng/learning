#include<iostream>
using namespace std;
#include<unistd.h>

int main(){
    cout << "before fork()" << endl;
    fork();
    cout << "after fork()" << endl;
}
