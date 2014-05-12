#include<stdio.h>
#include<string.h>

char* my_strcpy_end(char *dst,char const *src){
    strcpy(dst,src);
    return dst+strlen(dst);
}

int main(){
    char s1[100]="hello";
    printf("%s\n",my_strcpy_end(s1,"world!"));
}
