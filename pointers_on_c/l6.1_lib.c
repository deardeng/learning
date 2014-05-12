#include<stdio.h>
#include<string.h>

int main(){
    char *s1="ABCDEF";
    char *s2="XRCQEF";
    printf("%s\n",strpbrk(s1,s2));
}
