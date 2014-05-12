#include<stdio.h>
#include<assert.h>

#define TRUE 1
#define FALSE 0

int find_char(char **strings,char value){
    assert(strings!=NULL);
    while(*strings!=NULL){
        while(**strings!='\0'){
            if(*(*strings)++==value)
                return TRUE;
        }
        strings++;
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
    printf("%p\n",*p);
    printf("%c\n",ch);
    printf("%d\n",find_char(p,ch));
    printf("%p\n",*p);
    scanf("%c",&ch);
    scanf("%c",&ch);
    printf("%p\n",*p);
    printf("%d\n",find_char(p,ch));
    printf("%p\n",*p);
    return 0;
}
