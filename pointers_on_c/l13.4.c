#include<stdio.h>
#include<string.h>

void swap(char *i,char *j,int recsize){
    char x;
    while(recsize-->0){
        x=*i;
        *i++=*j;
        *j++=x;
    }
}

void sort(char *base,int nel,int recsize,int (*comp)(const char *,const char *)){
    register char *i;
    register char *j;
    register char *last;
    last=base+(nel-1)*recsize;
    for(i=base;i<last;i+=recsize)
        for(j=i+recsize;j<=last;j+=recsize)
            if(comp(i,j)>0)
                swap(i,j,recsize);
}

int main(){
    char s[]="afecdb";
    sort(s,6,1,strcmp);
    printf("%s\n",s);
}
