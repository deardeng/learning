#include "passwd.h"
int set_disp_mode(int fd,int option){
    int err;
    struct termios term;
    if(tcgetattr(fd,&term)==-1){
        perror("Cann't get the attribution of the term\n");
        return 1;
    }
    if(option)
        term.c_lflag|=ECHOFLAGS;
    else
        term.c_lflag&=~ECHOFLAGS;
    err=tcsetattr(fd,TCSAFLUSH,&term);
    if(err==-1&&err==EINTR){
        perror("Cann't set the attribution of the term\n");
        return 1;
    }
    return 0;
}

void getpasswd(char* passwd,int size){
    int c;
    int n=0;
    printf("Please Input passwd:");
    do{
        c=getchar();
        if((c!='\n')|(c!='\r')){
            passwd[n++]=c;
        }
    }while(c!='\n'&&c!='\r'&&n<(size-1));
    passwd[n]='\0';
}

char passwd[20];
char* inputpasswd(){
    char *p;
    set_disp_mode(STDIN_FILENO,0);
    getpasswd(passwd,sizeof(passwd));
    p=passwd;
    while(*p!='\n')
        p++;
    *p='\0';
    set_disp_mode(STDIN_FILENO,1);
    return passwd;
}
