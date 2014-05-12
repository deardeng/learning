#include<stdlib.h>
#include<stdio.h>

size_t strlen(char *string){
    int length=0;
    while(*string++!='\0')
        length++;
    return length;
}
int main(){
    char *s1="hello,world";
    printf("%d\n",strlen(s1));
    return 0;
}
