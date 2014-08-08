#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>


#define ERR_EXIT(m)         \
    do{                     \
        perror(m);          \
        exit(EXIT_FAILURE); \
    }while(0)

typedef struct stu{
    char name[32];
    int age;
} STU;

int main(int argc, const char *argv[])
{
    int shmid;
    shmid = shmget(1234,sizeof(STU),IPC_CREAT|0665);
    if(shmid == -1)
        ERR_EXIT("shmget");

    STU *p;
    p = (STU*)shmat(shmid,NULL,0);
    if(p == (void*)-1)
        ERR_EXIT("shmat");
    strcpy(p->name,"lisi");
    p->age = 20;

    while(1){
        if(memcmp(p,"quit",4)==0)
            break;
    }
    shmdt(p);
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}
