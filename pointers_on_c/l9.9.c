#include<stdio.h>
#include<string.h>

int count_chars(char const *str,char const *chars){
    int count=0;
    while((str=strpbrk(str,chars))!=NULL){
        count++;
        str++;
    }
    return count;
}

int main(){
    char *s1="hello,llo,world";
    printf("%d\n",count_chars(s1,"le"));
}
