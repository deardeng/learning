#include<stdio.h>
#include<stdlib.h>

int main(){
    int ch;
    while((ch=getchar())!=EOF){
        if(ch >= 'A' && ch <= 'Z')
            ch = (char)(ch-'A'+'a');
        putchar(ch);
    }
}
