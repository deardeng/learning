#include<stdio.h>
#include<math.h>

int fun(int m,int k,int xx[]);

int main(){
    int a,b,i;
    int c[100];
    printf("please input two number,first is begin,second is count (*,*)\n");
    scanf("%d,%d",&a,&b);
    int n=fun(a,b,c);
    for(i=0;i<n;i++)
        printf("%d ",c[i]);
    printf("\n");
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

int fun(int m,int k,int xx[]){
    int i,j=0,cont=0;
    i=m+1;
    do{
        if(is_primenum(i)){
            xx[j++]=i;
            cont++;
        }
        i++;
    }while(cont< k);
    return j;
}
