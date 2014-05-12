#include<iostream>
using namespace std;

int main(){
    void f(int &);
    int a=0;
    f(a);
    cout << "a=" << a << endl;
}
void f(int &x){
    ++x;
    cout << x << endl;
}
