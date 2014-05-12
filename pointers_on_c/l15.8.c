#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<ctype.h>

#define BUFFER_SIZE 64

void dump(FILE *stream){
    unsigned int offset;
    unsigned char data[16];
    int len;
    char buffer[BUFFER_SIZE];

    memset(buffer,' ',BUFFER_SIZE-1);
    buffer[45]='*';
    buffer[62]='*';
    buffer[BUFFER_SIZE-1]='\0';

    offset=0;
    while((len=fread(data,1,16,stream))>0){
        char *hex_ptr;
        char *char_ptr;
        int i;

        sprintf(buffer,"%06X  ",offset);
       // buffer[7]=' ';

        hex_ptr=buffer+8;
        char_ptr=buffer+46;
        memset(hex_ptr,' ',35);
        memset(char_ptr,' ',16);

        for(i=0;i<len;i++){
            sprintf(hex_ptr,"%02X",data[i]);
            hex_ptr+=2;
            *hex_ptr=' ';

            if(i%4==3)
                hex_ptr++;

            if(isprint(data[i])||data[i]==' ')
                *char_ptr++=data[i];
            else
                *char_ptr++='.';
        }
        puts(buffer);
        offset+=len;
    }
}

int main(int argc,char **argv){
    if(argc<=1)
        dump(stdin);
    else{
        FILE *stream;
        stream=fopen(argv[1],"rb");
        if(stream==NULL){
            perror(argv[1]);
            exit(EXIT_FAILURE);
        }
        dump(stream);
        fclose(stream);
    }
    return EXIT_SUCCESS;
}
