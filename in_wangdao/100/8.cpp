#include<iostream>
using namespace std;

float fun(int n);

int main(){
    int b;
    cout << "input a number:" << endl;
    cin >> b;
    cout << "the calulate result is :"<< (float)fun(b) << endl;
}

float fun(int n){
    float num=0;
    int cont=0;
    for(int i=1;i<=n;i++){
        cont+=i;
        num+=(1/static_cast<float>(cont));
    }
    return num;
}
