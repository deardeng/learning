#include<stdio.h>

int main(){
    int a[5]={3,4,5,4,3};
    int sum=0;
    sum= sum^a[0]^a[1]^a[2]^a[3]^a[4];
    printf("%d\n",sum);
}
