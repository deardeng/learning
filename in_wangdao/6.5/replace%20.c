/*去掉多余的空格，tab，多个空格用一个空格代替。*/
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[128];
    printf("input a string:\n");
    fgets(str,128,stdin);
    char *p=str,*bg=str,*end;
    int count=0;
    int len=strlen(str);
    while(*p!='\0'&&*p!='\n'){
        if(*p!=' '&&*p!='\t')
            bg=p;
        else{
            p++,count++;
            continue;
        }
        end=bg;
        while(*end!=' '&&*end!='\t'&&*end!='\n')
            end++,count++;
        while(bg!=end){
            putchar(*bg);
            bg++;
        }
        if(count!=len-1)
            printf("%%20");
        p=end;
    }
    putchar('\n');
    printf("count=%d\n",count);
    printf("len=%d\n",len);
}
