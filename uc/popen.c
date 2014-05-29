#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    char buf[128];
    FILE *f=popen("ls -l","r");
    if(f==NULL)return -2;
    int fd=fileno(f);
    if(fd==0)return -1;
    int r;
    printf("=====================\n");
    while((r=read(fd,buf,128))>0){
        buf[r]=0;
        printf("++++++++\n");
        printf("%s",buf);
        printf("++++++++\n");
    }
    printf("=====================\n");
    close(fd);
    pclose(f);
}
