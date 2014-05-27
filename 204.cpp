#include<iostream>
using namespace std;

int intc(int &val){
    return ++val;
}

int main(){
    short v1=0;
    const int v2=42;
    int v3=intc(v1);
    v3=incr(v2);
}
