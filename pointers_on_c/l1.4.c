#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1001

int main(void){
    char input[MAX_LEN];
    int len;
    char longest[MAX_LEN];
    int longest_len;

    longest_len=-1;

    while(gets(input)!=NULL){
        len=strlen(input);
        if(len>longest_len){
            longest_len = len;
            strcpy(longest,input);
        }
    }

    if(longest_len>=0)
        puts(longest);
    return EXIT_SUCCESS;
}
