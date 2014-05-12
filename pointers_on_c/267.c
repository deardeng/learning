#include<stdio.h>
#define TRUE 1

void process_standard_input(void){
    printf("%s","process_standard_input");
}
void process_file(char *file_name){}

int option_a,option_b;

int main(int argc,char **argv){
    while(*++argv&&**argv=='-'){
        switch(*++*argv){
            case 'a':
                option_a=TRUE;
                break;
            case 'b':
                option_b=TRUE;
                break;
        }
    }
    if(!*argv)
        process_standard_input();
    else{
        do{
            process_file(*argv);
        }while(*++argv);
    }
}

