#include<stdio.h>
int gcd(int m,int n){
    int r;
    if(m<=0||n<=0)
        return 0;
    do{
        r=m%n;
        m=n;
        n=r;
    }while(r>0);
    return m;
}
int main(){
    printf("%d\n",gcd(10,15));
    printf("%d\n",gcd(7,15));
}
