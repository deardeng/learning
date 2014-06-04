#include<iostream>
using namespace std;

unsigned fun(unsigned w);

int main(){
    int n;
    cout << "input a bigger than 10 number : ";
    cin >> n;
    cout << "after change the number is :" << fun(n) << endl;
}

unsigned fun(unsigned w){
    int cnt=0;
    int save=w;
    do{
        w=w/10;
        cnt++;
    }while(w!=0);
    int num=1;
    for(int i=1;i<cnt;i++){
        num*=10;
    }
    return save%num;
}
