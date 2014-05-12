#include<stdio.h>

int ascii_to_integer(char *string){
    int value;
    value=0;

    while(*string>='0'&&*string<='9'){
        value*=10;
        value+=*string-'0';
        string++;
    }

    if(*string!='\0')
        value=0;
    return value;
}

int main(){
    printf("%d\n",ascii_to_integer("12345"));
    printf("%d\n",ascii_to_integer("12x45"));
}
