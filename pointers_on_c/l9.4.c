#include<string.h>
#include<stdio.h>
#include<stddef.h>

size_t my_strlen(char const *string,int size){
    register size_t length;

    for(length=0;length<size;length++)
        if(*string++=='\0')
            break;
    return length;
}

char* my_strcat(char *dst,char const *src,int size){
    int length;
    size-=1;
    length=size-(int)my_strlen(dst,size);
    if(length>0){
        strncat(dst,src,length);
        dst[size]='\0';
    }
    return dst;
}

int main(){
    char *p1="hello,world";
    char p2[100]="deardeng";
    printf("%s\n",my_strcat(p2,p1,15));
}
