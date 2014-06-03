#include<stdio.h>

void fun(char *tt,int pp[]);

int main(){
    int i,p[26];
    char j;
    char str[128];
    printf("please input a sentence:");
    fgets(str,128,stdin);
    for(i=0;i<26;i++){
        p[i]=0;
    }
    fun(str,p);
    j='a';
    for(i=0;i<26;i++,j++)
        printf("%c:%d ",j,p[i]);
    putchar('\n');
}

void fun(char *tt,int pp[]){
    while(*tt!='\0'){
        pp[*tt-'a']++;
        tt++;
    }
}
