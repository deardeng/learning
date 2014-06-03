#include<iostream>
using namespace std;

void fun(int *s,int t,int *k);

int main(){
    int a[10];
    int k;
    cout << "input ten numbers for a vector to a max element" << endl;
    for(int i=0;i<10;i++){
        cin >> a[i];
    }
    fun(a,10,&k);
    cout << "the max element is " << a[k] << " and it index is" << k+1 << endl;
}

void fun(int *s,int t,int *k){
    int max=0;
    for(int i=0;i<t;i++){
        if(s[i]>max){
            max=s[i];
            *k=i;
        }
    }
}
