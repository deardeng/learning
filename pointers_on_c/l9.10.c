#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

int palindrome(char *string){
    char *string_end;
    string_end=string+strlen(string)-1;
    while(TRUE){
        while(!isalpha(*string))
            string++;
        while(!isalpha(*string_end))
            string_end--;
        if(string_end <= string)
            return TRUE;

        if(tolower(*string)!=tolower(*string_end))
            return FALSE;
        string++;
        string_end--;
    }
}

int main(){
    char *p1="Hellolleh";
    char *p3="hel1alolleh";
    char *p2="@@##$!!@@#$@#@!@!@";
    printf("string p1:%d\n",palindrome(p1));
    printf("string p2:%d\n",palindrome(p2));
    printf("string p3:%d\n",palindrome(p3));
}
