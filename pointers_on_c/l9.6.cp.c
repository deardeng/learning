#include<stdio.h>
#include<string.h>

char* my_strcpy_end(register char *dst,register char const *src){
    while((*dst++=*src++)!='\0');
    return dst-1;
}

int main(){
    char s1[100]="hello";
    printf("%s\n",my_strcpy_end(s1,"world!"));
}
