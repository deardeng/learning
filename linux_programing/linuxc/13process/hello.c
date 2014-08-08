#include <unistd.h>
#include <stdio.h>

extern char** environ;

int main(void){
    printf("hello pid = %d\n",getpid());
    int i;
    for(i=0;environ[i]!=NULL;++i){
        printf("%s\n",environ[i]);
    }
    return 0;
}
