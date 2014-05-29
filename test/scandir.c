#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

int comp(const struct dirent **a,const struct dirent **b){
    return strcmp((*a)->d_name,(*b)->d_name);
}

int filt(const struct dirent *c){
    if(c->d_name[0]=='.')
        return 0;
    else
        return 1;
}

int main(){
    struct dirent **d;
    int r;
    int i;
    r=scandir("/home/dengxin",&d,filt,comp);
    printf("child dir's num:%d\n",r);
    for(i=0;i<r;i++){
        printf("%s\n",d[i]->d_name);
    }

    while(*d){
        printf("%s\n",(*d)->d_name);
        d++;
    }
}
