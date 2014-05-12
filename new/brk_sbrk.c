#include<stdio.h>
#include<unistd.h>
int brk(void *);
void* sbrk(int);
int isPrime(int a){
    int i;
    for(i=2;i<a;i++)
        if(a%i==0)
            return  -1;
    return 0;
}
int main(){
    int i;
    int *r;
    int *p;
    p=(int *)sbrk(0);
    r=p;
    for(i=2;i<1000;i++)
        if(!isPrime(i)){
            brk(r+1);
            *r=i;
            r=(int *)sbrk(0);
        }
    r=p;
    i=0;
    while(r!=(int *)sbrk(0)){
        printf("%d\n",*r);
        r++;
    }
}
