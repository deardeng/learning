#include<stdio.h>
int gcd(int m,int n){
    int r;
    if(m<=0||n<=0)
        return 0;
    r=m%n;
    return r>0?gcd(n,r):n;
}
int main(){
    printf("%d\n",gcd(10,15));
    printf("%d\n",gcd(7,15));
}
