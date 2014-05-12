#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str1[10]="hello";
    char *str2="world?";
    printf("%d\n",strlen(str1));
    printf("%d\n",strlen(str2));
    return 0;
}
