#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#define DELTA 2

char* readstring(){
    static char *buffer=NULL;
    static int buffer_size=0;
    int ch;
    int len;
    char *bp;
    bp=buffer;
    len=0;

    do{
        ch=getchar();
        if(ch=='\n'||ch==EOF)
            ch='\0';

        if(len>=buffer_size){
            buffer_size+=DELTA;
            buffer=(char *)realloc(buffer,buffer_size);
            assert(buffer!=NULL);
            bp=buffer+len;
        }
        *bp++=ch;
        len+=1;
    }while(ch!='\0');

   // bp=(char *)malloc(len);
   // assert(bp!=0);
   // strcpy(bp,buffer);
   // printf("\n");
    return buffer;
}

int main(){
    printf("%s\n",readstring());
}
