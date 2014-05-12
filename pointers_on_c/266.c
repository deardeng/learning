#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv){
    while(*++argv)
        printf("%s\n",*argv);
    return EXIT_SUCCESS;
}
