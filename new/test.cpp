#include<iostream>
using namespace std;
#include<signal.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int v=0;
int x=0;
void func(int sig){
    cout << "time out!" << endl;
    cout << "V: " << v << endl;
    cout << "X: " << x << endl;
}

int main(){
    signal(SIGALRM,func);
    srand(time(NULL));
    alarm(20);
    for(int i=0;i<10;i++){
        int n1=rand()%10;
        int n2=rand()%10;
        cout << n1 << '+' << n2 << '=';
        int sum;
        cin >> sum;
        if(sum==n1+n2)
            v++;
        else 
            x++;
    }
    cout << "You So Fast!" << endl;
    raise(SIGALRM);
}
