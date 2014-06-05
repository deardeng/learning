#include <stdio.h>

int main(int argc, const char *argv[])
{
    char str[128];
    printf("input a string:\n");
    fgets(str,128,stdin);
    char *p=str,*bg=str,*end;
    int count=0;
    while(*p!='\0'&&*p!='\n'){
        if(*p!=' '&&*p!='\t')
            bg=p;
        else{
            p++;
            continue;
        }
        end=bg;
        while(*end!=' '&&*end!='\t'&&*end!='\n')
            end++;
        while(bg!=end){
            putchar(*bg);
            bg++;
        }
        count++;
        putchar('\n');
        p=end;
    }
    printf("your input have %d words\n",count);
}
