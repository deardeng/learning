#include<stdio.h>
#include<string.h>

char* my_strrpbrk(char const *s1,char const *s2){
    register char *last;
    register char *current;

    last = NULL;

    if(*s2!='\0'){
        current=strpbrk(s1,s2);
        while(current!=NULL){
            last=current;
            current=strpbrk(last+1,s2);
        }
    }
    return last;
}

int main(){
    char *p="hello,world!world!";
    char *q="or";
    printf("%s\n",my_strrpbrk(p,q));
    printf("%s\n",strpbrk(p,q));
}
