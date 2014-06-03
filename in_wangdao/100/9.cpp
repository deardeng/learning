#include<iostream>
using namespace std;

float fun(int m,int n);

int main(){
    int m,n;
    cout << "input m and n ,m must bigger than n" << endl;
    cin >> m >> n;
    cout << "the calulate result is :" << fun(m,n) << endl;
}

int jiechen(int n){
    int sum=1;
    for(int i=1;i<=n;i++){
       sum*=i;
    }
    return sum;
}

float fun(int m,int n){
    float p;
    int temp;
    temp=jiechen(n)*jiechen(m-n);
    p=jiechen(m)/temp;
    return p;
}
