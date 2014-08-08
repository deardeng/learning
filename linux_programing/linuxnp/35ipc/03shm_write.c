#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

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

int main(void){
    int shmid;
    shmid = shm_open("/xyz",O_RDWR,0);
    if(shmid == -1)
        ERR_EXIT("shm_open");

    printf("shm_open succ\n");

    struct stat buf;
    if(fstat(shmid,&buf)==-1)
        ERR_EXIT("fstat");

    printf("size = %ld mode = %o\n",buf.st_size,buf.st_mode & 0777);

    STU *p;
    p = (STU*)mmap(NULL,buf.st_size,PROT_WRITE,MAP_SHARED,shmid,0);
    if(p == MAP_FAILED)
        ERR_EXIT("mmap");

    strcpy(p->name,"test");
    p->age = 20;

    close(shmid);

    return 0;
}
