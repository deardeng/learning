#include<stdio.h>
#include<stdlib.h>
#include"l15.11.part.h"
#include"l15.11.io.h"
#include"l15.11.process.h"

int main(int ac,char **av){
    if(ac!=2){
        fprintf(stderr,"Usage:inventory inv-filename\n");
        return EXIT_FAILURE;
    }
    if(open_file(av[1])){
        while(process_request());
        close_file();
    }
    return EXIT_SUCCESS;
}
