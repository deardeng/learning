#include<stdio.h>

#define NUL '\0'
#define DIGIT_SELECTOR '#'
#define SIGNIFICANCE_START '!'
#define TRUE 1
#define FALSE 0
#define reg register

char* edit(reg char *pattern,reg char *digits){
    int digit;
    int pat_char;
    int fill;
    int significance;
    char *first_digit;

    if(pattern == NULL || digits == NULL || (fill = *pattern) == '\0')
        return NULL;
    first_digit = NULL;
    significance = FALSE;

    while((pat_char=*++pattern)!=NUL){
        switch(pat_char){
            case DIGIT_SELECTOR:
            case SIGNIFICANCE_START:
                if((digit=*digits++)==NUL){
                    *pattern=NUL;
                    return first_digit;
                }
                if(digit==' ')
                    digit='0';
                if(digit!='0'||pat_char==SIGNIFICANCE_START){
                    if(!significance)
                        first_digit=pattern;
                    significance=TRUE;
                }
                break;
            default:
                digit=pat_char;
                break;
        }
        *pattern=significance?digit:fill;
    }
    return first_digit;
}

int main(){
    char p1[100],p2[100];
    char *p=p1,*q=p2;
    do{
        printf("Please input the digit_string\n");
        fgets(p,100,stdin);
        printf("And please input the format_string\n");
        fgets(q,100,stdin);
        printf("The formated String is:");
        edit(p2,p1);
        printf("%s\n",p2);
    }while(getchar()!=EOF);
}

