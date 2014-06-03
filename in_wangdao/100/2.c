#include<stdio.h>

int fun(int *a,int n,int *b);
int main(){
    int i,n;
    int a[101],b[20];
    for(i=1;i<=100;i++)
        a[i]=i;
    n=fun(a+1,100,b);
    printf("The B vectro elements are: ");
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
}

int fun(int *a,int n,int *b){
    int i,j=0;
    for(i=0;i<100;i++){
        if(a[i]%7==0||a[i]%11==0){
            if(a[i]%7==0&&a[i]%11==0)
                continue;
            else
                b[j++]=a[i];
        }
    }
    return j;
}
