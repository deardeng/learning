#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define ERR_EXIT(m)         \
    do{                     \
        perror(m);          \
        exit(EXIT_FAILURE); \
    }while(0)

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[1];    /* message data */
};

#define MSGMAX 8192
int main(int argc, const char *argv[])
{
    int flag = 0;
    int type = 0;
    int opt;
    while(1){
        opt = getopt(argc,(char * const*)argv,"nt:");
        if(opt == '?')
            exit(EXIT_FAILURE);
        if(opt == -1)
            break;
        switch(opt){
            case 'n':
                //printf("AAAA\n");
                flag |= IPC_NOWAIT;
                break;
            case 't':
                //printf("BBBB\n");
                //int n = atoi(optarg);

                type = atoi(optarg);
                break;
        }
    }
    int msgid;
    msgid = msgget(1234,0);
    if(msgid == -1)
        ERR_EXIT("msgget");

    struct msgbuf* ptr;
    ptr = (struct msgbuf*)malloc(sizeof(long)+MSGMAX);
    ptr->mtype = type;

    int n = 0;
    if((n=msgrcv(msgid,ptr,MSGMAX,type,flag))<0)
        ERR_EXIT("msgsnd");
    printf("read %d bytes type = %ld\n",n,ptr->mtype);
    return 0;
}
