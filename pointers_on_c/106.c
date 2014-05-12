#include<stdio.h>

#define TRUE 1
#define FALSE 0

int find_char(char **strings,char value){
    char *string;
    while((string=*strings++)!=NULL){
        while(*string!='\0'){
            if(*string++ == value)
                return TRUE;
        }
    }
    return FALSE;
}

int main(){
    char *p[10],s1[3][10];
    int i;
    char ch;
    for(i=0;i<3;i++){
        scanf("%s",s1+i);
        //printf("%s\n",s1+i);
        p[i]=*(s1+i);
    }
    p[i]=NULL;
    scanf("%c",&ch);
    scanf("%c",&ch);
    printf("%p\n",p);
    printf("%d\n",find_char(p,ch));
    printf("%p\n",p);
    scanf("%c",&ch);
    scanf("%c",&ch);
    printf("%p\n",p);
    printf("%d\n",find_char(p,ch));
    printf("%p\n",p);
    return 0;
}
