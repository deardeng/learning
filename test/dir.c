#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

int main(){
    DIR *d;
    struct dirent *de;

    d=opendir("/home/dengxin");
    if(d==NULL){
        printf("opendir:%m\n");
        exit(-1);
    }
    while(de=readdir(d)){
        printf("%s,\t%d\n",de->d_name,de->d_type);
    }

    closedir(d);

}
