#include<stdio.h>

#define NUL '\0'
#define TRUE 1
#define FALSE 0

char* match(char *str,char *want){
    while(*want!=NUL)
        if(*str++!=*want++)
            return NULL;
    return str;
}
int del_substr(char *str,char *substr){
    char *next,*ptr;
    ptr=str;

    while(*str!=NUL){
        next=match(str,substr);
        if(next!=NULL)
            break;
        str++;
    }

    if(*str==NUL)
        return FALSE;

    while(*str++ = *next++);
    printf("%s\n",ptr);
        
    return TRUE;
}

int main(){
    char p[100]="ABCDEFG";
    char q[100]="CDE";
    printf("%d\n",del_substr(p,q));
}
