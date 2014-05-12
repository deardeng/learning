#include<stdio.h>
#include<string.h>

char* my_strrstr(char const *s1,char const *s2){
    register char *last;
    register char *current;

    last = NULL;

    if(*s2!='\0'){
        current=strstr(s1,s2);
        while(current!=NULL){
            last=current;
            current=strstr(last+1,s2);
        }
    }
    return last;
}

int main(){
    char *p="hello,world!world!";
    char *q="or";
    printf("%s\n",my_strrstr(p,q));
}
