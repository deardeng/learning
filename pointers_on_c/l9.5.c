#include<stdio.h>
#include<string.h>

void my_strncat(char *dest,char *src,int dest_len){
    register int len;

    len=strlen(dest);
    dest_len-=len+1;

    if(dest_len>0)
        strncat(dest+len,src,dest_len);
}

int main(){
    char *p1="hello,world";
    char p2[100]="deardeng";
    my_strncat(p2,p1,100);
    printf("%s\n",p2);
}
