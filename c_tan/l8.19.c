#include<stdio.h>
#define NEWSIZE 1000
char newbuf[NEWSIZE];
char *newp=newbuf;

char *new(int n){
    if(newp+n <= newbuf+NEWSIZE){
        newp += n;
        return newp-n;
    }
    else
        return NULL;
}

void free(char *p){
    if(p>=newbuf&&p<newbuf+NEWSIZE)
        newp=p;
}
