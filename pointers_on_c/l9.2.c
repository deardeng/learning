#include<string.h>
#include<stdio.h>
#include<stddef.h>

size_t my_strnlen(char const *string,int size){
    register size_t length;
    for(length=0;length<size;length++)
        if(*string++=='\0')
            break;
    return length;
}

int main(){
    char *p="hello,who are you ? what's your name?";
    printf("%d\n",my_strnlen(p,50));
}
