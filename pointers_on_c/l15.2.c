#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 5

int main(){
    char buf[BUFSIZE];
    while(gets(buf)!=NULL)
        puts(buf);
    return EXIT_SUCCESS;
}
