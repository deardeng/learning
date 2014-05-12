#include<stdio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

int format(char *pattern,char *digits){
    char *patternp,*digitp;

    if(pattern==NULL||digits==NULL)
        return FALSE;
    patternp=pattern+strlen(pattern)-1;
    digitp=digits+strlen(digits)-1;
    if(digitp<digits)
        return FALSE;

    while(patternp >= pattern && digitp >= digits){
        if(*patternp == '#'){
            *patternp--=*digitp--;
            continue;
        }
        patternp--;
    }
    while(patternp>=pattern){
        if(*patternp=='.'){
            char *p0;
            for(p0=patternp+1;*p0==' ';*p0++='0');
            *(--patternp)='0';
            --patternp;
            continue;
        }
        *patternp--=' ';
    }
    return digitp < digits;
}

int main(){
    char p1[100],p2[100];
    do{
        printf("Please input the digit_string\n");
        scanf("%s",p1);
        printf("And please input the format_string\n");
        scanf("%s",p2);
        format(p2,p1);
        printf("The formated String is:");
        printf("%s\n",p2);
        getchar();
    }while(getchar()!=EOF);
}
