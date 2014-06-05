#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[128];
    printf("input a string:\n");
    fgets(str,128,stdin);
    int len=strlen(str);
    int i;
    int ch;
    for(i=0;i<len/2;i++){
        ch=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]= ch;
    }
    printf("your input after reverse: %s\n",str);
}
