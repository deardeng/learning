#include<stdio.h>
void fun(int x,int pp[],int *n);

int main(){
    int i,n,a,pp[100];
    printf("input a number:\n");
    scanf("%d",&a);
    fun(a,pp,&n);
    printf("the result has %d numbers,that are :",n);
    for(i=0;i<n;i++){
        printf("%d ",pp[i]);
    }
    putchar('\n');
}

void fun(int x,int *pp,int *n){
    int i,j=0;
    for(i=1;i<=x;i++){
        if(x%i==0)
            pp[j++]=i;
    }
    *n=j;
}
