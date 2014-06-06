#include <iostream>
using namespace std;

void fun(int m,int *a,int *n);

int main(){
    cout << "input a number:" << endl;
    int a;
    cin >> a;
    int k;
    int b[100];
    fun(a,b,&k);
    for(int i=0;i<k;i++){
        cout << b[i] << ' ';
    }
    cout << "has " << k << " numbers "<< endl;
}

void fun(int m,int *a,int *n){
    int i;
    int j;
    for(j=0,i=2;i<m;i++)
        if(i%7==0||i%11==0)
            a[j++]=i;
    *n=j;
}
