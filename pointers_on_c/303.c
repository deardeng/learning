#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv){
    int exit_status=EXIT_SUCCESS;
    FILE *input;

    while(*++argv!=NULL){
        input = fopen(*argv,"r");
        if(input==NULL){
            perror(*argv);
            exit_status=EXIT_SUCCESS;
            continue;
        }
        
        if(fclose(input)){
            perror("fclose");
            exit(EXIT_FAILURE);
        }
    }
    return exit_status;
}
