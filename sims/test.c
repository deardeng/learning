#include <stdio.h>
int main(int argc, const char *argv[])
{
    int ch;
    char s[100],*p=s;
    while((ch=getchar()!='\r'))
        *p++=ch,putchar('*');
    putchar('\n');
    puts(s);
    return 0;
}
