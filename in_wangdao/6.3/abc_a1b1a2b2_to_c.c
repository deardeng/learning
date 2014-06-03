#include<stdio.h>

int main(){
    int a,b,c;
    printf("Please input two numbers\n");
    scanf("%d,%d",&a,&b);
    c=a/10*1000+b/10*100+a%10*10+b%10;
    printf("The a1b1a2b2 is: %d\n",c);
}
