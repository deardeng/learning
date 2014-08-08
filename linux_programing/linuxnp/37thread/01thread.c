#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define ERR_EXIT(m) \
    do  \
    {   \
        perror(m); \
        exit(EXIT_FAILURE); \
    }while(0)

void* thread_routine(void *arg){
    int i;
    for(i=0;i<20;i++){
        printf("B");
        fflush(stdout);
        usleep(20);
        //if(i == 3)
        //    pthread_exit("ABC");
    }
    sleep(3);
    return (void*)"DEF";
}

int main(void){
    pthread_t tid;
    int ret;
    if((ret = pthread_create(&tid,NULL,thread_routine,NULL)) != 0){
        fprintf(stderr,"phtread_create: %s\n",strerror(ret));
        exit(EXIT_FAILURE);
    }

    int i;
    for(i=0;i<20;i++){
        printf("A");
        fflush(stdout);
        usleep(20);
    }
    void *value;
    //pthread_join(tid,&value);
    if((ret = pthread_join(tid,&value)) != 0){
        fprintf(stderr,"phtread_join: %s\n",strerror(ret));
        exit(EXIT_FAILURE);
    }
    printf("\n");
    printf("return msg = %s\n",(char*)value);
    return 0;
}
