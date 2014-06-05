#include <stdio.h>

int main(int argc, const char *argv[])
{
    char str[128];
    printf("input a string:\n");
    fgets(str,128,stdin);
    char *p=str;
    char *q=str;
    int flag=1;
    while(*p!='\0'&&*p!='\n'){
        if(*p==' '||*p=='\t'){
            if(*q==' '||*q=='\t'){
                q++;
                p++;
                continue;
            }
            p++;
            if(flag)
                putchar(' '),flag=0;
        }
        else{
            putchar(*p);
            p++;
        }
    }
    putchar('\n');
    return 0;
}
