#ifndef _EXTERNS_H_
#define _EXTERNS_H_

#include "def.h"

extern int append;
extern char *lineptr;
extern char *avptr;
extern char cmdline[MAXLINE+1];
extern COMMAND cmd[PIPELINE];
extern char avline[MAXLINE+1];
extern char infile[MAXNAME + 1];
extern char outfile[MAXNAME + 1];
extern int cmd_count;
extern int backgnd;
extern int lastpid;

#endif //_EXTERNS_H_
