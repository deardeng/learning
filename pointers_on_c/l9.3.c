#include<stdio.h>
#include<string.h>

char* my_strcpy(char *dst,char const *src,int size){
    strncpy(dst,src,size);
    dst[size-1]='\0';

    return dst;
}

int main(){
    char *p="hello,world!";
    char q[100];
    printf("%s\n",my_strcpy(q,p,20));
    printf("%s\n",my_strcpy(q,p,10));
}
