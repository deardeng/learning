#include<stdio.h>

extern char **environ;

int main(){
    int i;
    for(i=0;*environ[i];i++)
        printf("*environ[%d]:%s\n",i,environ[i]);
    return 0;
}
