#include "parse.h"
#include "init.h"
#include "def.h"

char cmdline[MAXLINE+1];
char avline[MAXLINE+1];
char infile[MAXNAME + 1];
char outfile[MAXNAME + 1];

char *lineptr;
char *avptr;

int append;
int cmd_count;
int backgnd;
COMMAND cmd[PIPELINE];
int lastpid;

int main(void){
    setup();
    shell_loop();
    return 0;
}
