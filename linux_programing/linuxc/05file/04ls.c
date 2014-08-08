#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)

//#define ERR_EXIT(m) (perror(m),exit(EXIT_FAILURE))


int main(int argc,char *argv[]){
    DIR *dir = opendir(".");
    struct dirent *de;
    while((de = readdir(dir))!=NULL){
        if(!strncmp(de->d_name,".",1))
            continue;
        printf("%s\n",de->d_name);
    }
    exit(EXIT_SUCCESS);
    return 0;
}
