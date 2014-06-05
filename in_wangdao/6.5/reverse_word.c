#include <stdio.h>

int main(int argc, const char *argv[])
{
    char str[128];
    printf("input a string:\n");
    fgets(str,128,stdin);
    char *p=str,*bg=str,*end;
    int ch;
    char *temp;
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
        temp=end;
        while(bg<(end-1)){
            ch=*bg;
            *bg=*(end-1);
            *(end-1)=ch;
            bg++;
            end--;
        }
        end=temp;
        p=end;
    }
    printf("your input have been reverse %s\n",str);
}
