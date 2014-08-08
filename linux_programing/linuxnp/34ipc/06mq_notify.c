#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define ERR_EXIT(m) \
    do \
{ \
    perror(m); \
    exit(EXIT_FAILURE); \
}while(0)

typedef struct stu{
    char name[32];
    int age;
} STU;

size_t size;
mqd_t mqid;
struct sigevent sigev;

void handle_singusr1(int sig){
    STU stu;
    mq_notify(mqid,&sigev);

    unsigned prio;
    if(mq_receive(mqid,(char*)&stu,size,&prio) == (mqd_t)-1)
        ERR_EXIT("mq_receive");
    printf("name = %s age =%d prio =%u\n",stu.name,stu.age,prio);


}

int main(int argc,char *argv[]){
    mqid = mq_open("/abc",O_RDONLY);
    if(mqid == (mqd_t)-1)
        ERR_EXIT("mq_open");

    struct mq_attr attr;
    mq_getattr(mqid,&attr);
    size = attr.mq_msgsize;
    signal(SIGUSR1,handle_singusr1);

    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;
    mq_notify(mqid,&sigev);

    for(;;)
        pause();

    mq_close(mqid);
       return 0;
}
