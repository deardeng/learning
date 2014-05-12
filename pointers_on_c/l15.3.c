#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 2

int main(){
    char buf[BUFSIZE];

    while(fgets(buf,BUFSIZE,stdin))
        fputs(buf,stdout);
    return EXIT_SUCCESS;
}
