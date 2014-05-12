#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* strdup(char const *string){
    char *new_string;

    new_string=(char *)malloc(strlen(string)+1);

    if(new_string!=NULL)
        strcpy(new_string,string);
    return new_string;
}

int main(){
    char *p1="hello,world";
    printf("%s\n",strdup(p1));
    return 0;
}
