#include<stdio.h>
#include<string.h>

char const* my_strrchr(char const *str,int ch){
    char const *prev_answer=NULL;
    for(;(str=strchr(str,ch))!=NULL;str++)
        prev_answer=str;
    return prev_answer;
}

int main(){
    char *s1="helloworld";
    printf("%s\n",my_strrchr(s1,'l'));
}
