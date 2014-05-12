#include<iostream>
using namespace std;

int main(){
    void f(int* &x);
    int a=0;
    int* b=&a;
    f(b);
    cout << "a=" << a << endl;
}
void f(int* &x){
    ++(*x);
    cout << *x << endl;
}
