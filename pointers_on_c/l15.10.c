#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

char file_output = FALSE;
char **do_args(char **);
unsigned short process(FILE *);
void print(unsigned short,char *);

int main(int ac,char **av){
    FILE *f;
    unsigned short sum;

    av=do_args(av);

    if(*av==NULL){
        if(file_output){
            fprintf(stderr,"-f illegal with standard input\n");
            exit(EXIT_FAILURE);
        }
        sum=process(stdin);
        print(sum,NULL);
    }
    else
        for(;*av!=NULL;++av){
            f=fopen(*av,"r");
            if(f==NULL)
                perror(*av);
            else{
                sum=process(f);
                fclose(f);
                print(sum,*av);
            }
        }
    return EXIT_SUCCESS;
}

unsigned short process(FILE *f){
    unsigned short sum;
    int ch;
    sum=0;
    while((ch=getc(f))!=EOF)
        sum+=ch;
    return sum;
}

void print(unsigned short sum,char *in_name){
    char *out_name;
    FILE *f;
    if(!file_output)
        printf("%u\n",sum);
    else{
        out_name=malloc(strlen(in_name)+5);
        if(out_name==NULL){
            fprintf(stderr,"malloc:out of memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(out_name,in_name);
        strcat(out_name,".cks");

        f=fopen(out_name,"w");
        if(f==NULL)
            perror(out_name);
        else{
            fprintf(f,"%u\n",sum);
            fclose(f);
        }
        free(out_name);
    }
}
char** do_args(char **av){
    while(*++av!=NULL&&**av=='-'){
        while(*++*av!='\0'){
            switch(**av){
                case 'f':
                    file_output=TRUE;
                    break;
                default:
                    fprintf(stderr,"Illegal option:%c\n",**av);
                    break;
            }
        }
    }
    return av;
}
