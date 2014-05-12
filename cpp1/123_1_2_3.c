#include<iostream>
using namespace std;
void show(int n){
    if(n>9){
        show(n/10);
        cout << ' ';
    }
    cout << n%10;
}
int main(){
    int n=123456789;
    show(n);
    return 0;
}
