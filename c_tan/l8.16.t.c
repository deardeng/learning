#include<stdio.h>
int main(){
    char str[50],*p;
    int a[50],*q;
    int b[20];
    int j=0,i=0,c=0;
    int d,e;
    printf("input a string:\n");
    gets(str);
    p=str;
    q=a;
    while(*(p+i)!='\0'){
        if((*(p+i)>='0')&&(*(p+i)<='9')){
            *q=*(p+i)-'0';
            j++;
            q++;
        }
        else{
            b[c]=j;
            c++;
            j=0;
        }
        i++;
    }
    i=0;e=0;
    for(;c-1>0;c--){
        d=b[i];
        for(j=0;j<d;j++)
            printf("%d",a[e++]);
        printf(" ");
        i++;
    }
    return 0;
}
