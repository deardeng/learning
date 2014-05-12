#include<stdio.h>

char *find_char(char* const str,char* const chars){
    char *cp;
    char *str1=str;
    if(str!=NULL&&chars!=NULL){
        for(;*str1!='\0';str1++){
            for(cp=chars;*cp!='\0';cp++)
                if(*str1==*cp)
                    return str1;
        }
    }
    return NULL;
}
int main(){
    char *s1="ABCDEF";
    char *s2="XRCQEF";
    printf("%s\n",find_char(s1,s2));
}
