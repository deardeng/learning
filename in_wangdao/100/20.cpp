#include<iostream>
using namespace std;
#include<cmath>

int fun(int lim,int xx[]);

int main(){
    int a,b,i;
    int c[100];
    cout << "please input a number,first is begin\n";
    cin >> a;
    int n=fun(a,c);
    for(i=0;i<n;i++)
        cout << c[i] << ' ';
    cout << endl;
}

int is_primenum(int n){
    int i;
    if(n==2)return 1;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int fun(int lim,int xx[]){
    int i,j=0;
    i=lim;
    do{
        if(is_primenum(i)){
            xx[j++]=i;
        }
        i--;
    }while(i>0);
    return j;
}
