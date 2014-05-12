#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char const whitespace[] = " \n\t\f\t\v";

int main(){
    char buffer[1001];
    int count;

    count=0;
    while(gets(buffer)){
        char *word;

        for(word=strtok(buffer,whitespace);word!=NULL;word=strtok(NULL,whitespace)){
            if(strcmp(word,"the")==0)
                count++;
        }
    }
    printf("%d\n",count);
    return EXIT_SUCCESS;
}
