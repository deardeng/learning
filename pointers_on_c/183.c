#include<stdio.h>
#include<string.h>

void print_tokens(char *line){
    static char whitespace[] = ":#";
    char *token;

    for(token=strtok(line,whitespace);token!=NULL;token=strtok(NULL,whitespace))
        printf("Next token is %s\n",token);
}

int main(){
    char s1[100]="hello#who:are:you#?";
    print_tokens(s1);
    
}
