#ifndef _FTP_PROTO_H_
#define _FTP_PROTO_H_
#include "session.h"
#include "common.h"
#include "privsock.h"

void handle_child(session_t *sess);
void ftp_relply(session_t *sess,int status,const char *text);
//int list_common(void);


#endif //_FTP_PROTO_H_
