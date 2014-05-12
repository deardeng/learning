#include<stdio.h>
#include<string.h>

char* my_strnchr(char const *str,int ch,int which){
    char *answer=NULL;
    while(--which>=0&&(answer=strchr(str,ch))!=NULL)
        str=answer+1;
    return answer;
}

int main(){
    char *p="hello,world";
    printf("%s\n",my_strnchr(p,'l',2));
}
