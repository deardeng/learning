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

#define MSGMAX 8192

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[MSGMAX];    /* message data */
};


void echo_srv(int msgid){
    struct msgbuf msg;
    memset(&msg,0,sizeof(msg));
    int n = 0;
    while(1){
        if((n=msgrcv(msgid,&msg,MSGMAX,1,0))<0)
            ERR_EXIT("msgsnd");
        int pid;
        pid = *((int*)msg.mtext);

        fputs(msg.mtext+4,stdout);
        msg.mtype = pid;
        msgsnd(msgid,&msg,n,0);

    }
}

int main(int argc, const char *argv[])
{
    int msgid;
    msgid = msgget(1234,IPC_CREAT|0666);
    if(msgid == -1)
        ERR_EXIT("msgget");

    echo_srv(msgid);
    return 0;
}
