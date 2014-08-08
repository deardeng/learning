#include "session.h"
#include "common.h"
#include "ftpproto.h"
#include "privparent.h"
#include "privsock.h"

void begin_session(session_t *sess){
    /*
       int sockfds[2];
       if(socketpair(PF_UNIX,SOCK_STREAM,0,sockfds)<0)
       ERR_EXIT("socketpair");

    */

    activate_oobinline(sess->ctrl_fd);

    priv_sock_init(sess);
    pid_t pid;
    pid = fork();
    if(pid < 0)
        ERR_EXIT("fork");

    if(pid == 0){
        //ftp
        priv_sock_set_child_context(sess);
        handle_child(sess);

    }
    else{
        //nobody
        struct passwd *pw = getpwnam("nobody");
        if(pw == NULL)
            return;

        if(setegid(pw->pw_gid) < 0)
            ERR_EXIT("setegid");

        if(seteuid(pw->pw_uid) < 0)
            ERR_EXIT("seteuid");
        priv_sock_set_parent_context(sess);
        handle_parent(sess);

    }
}
