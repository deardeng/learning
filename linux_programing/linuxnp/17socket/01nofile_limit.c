#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
 #include <sys/time.h>
#include <sys/resource.h>

#define ERR_EXIT(m)     \
    do{                 \
        perror(m);      \
        exit(EXIT_FAILURE);     \
    }while(0)

int main(void){
    struct rlimit rl;
    if(getrlimit(RLIMIT_NOFILE,&rl)<0)
        ERR_EXIT("getrlimit");
    printf("%d\n",(int)rl.rlim_max);

    rl.rlim_cur = 2048;
    rl.rlim_max = 2048;
    if(setrlimit(RLIMIT_NOFILE,&rl)<0)
        ERR_EXIT("setrlimit");
    if(getrlimit(RLIMIT_NOFILE,&rl)<0)
        ERR_EXIT("getrlimit");
    printf("%d\n",(int)rl.rlim_max);
    return 0;
}
