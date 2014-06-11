#ifndef _PASSWD_H_
#define _PASSWD_H_
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <errno.h>

#define ECHOFLAGS (ECHO|ECHOE|ECHOK|ECHONL)

int set_disp_mode(int fd,int option);
void getpasswd(char* passwd,int size);
char* inputpasswd();

#endif
