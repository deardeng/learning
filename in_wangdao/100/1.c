#include<stdio.h>

int fun(int* a,int n,int* below){
    int i,all=0,aver;
    for(i=0;i<n;i++){
        all+=a[i];
    }
    aver=all/n;
    int j=0;
    for(i=0;i<n;i++){
        if(a[i]<aver)
            below[j++]=a[i];
    }
    return j;
}
int main(){
    int score[10];
    int below[10];
    int i,n=0;
    for(i=0;i<10;i++){
        scanf("%d",&score[i]);
    }
    printf("the vector below element are:");
    n=fun(score,10,below);
    for(i=0;i<n;i++){
        printf("%d  ",below[i]);
    }
    printf("\n");
}
