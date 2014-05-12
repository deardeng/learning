#include<stdio.h>

void reverse_string(char *str){
    char *last_char,*ptr=str;
    for(last_char=str;*last_char!='\0';last_char++)
        ;
    last_char--;

    while(str < last_char){
        char temp;
        temp=*str;
        *str++=*last_char;
        *last_char--=temp;
    }
    printf("%s\n",ptr);
}

int main(){
    char s1[100]="hello,world!";
    reverse_string(s1);
};
