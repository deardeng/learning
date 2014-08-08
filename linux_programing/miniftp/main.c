#include "common.h"
#include "sysutil.h"
#include "session.h"
#include "str.h"
#include "tunable.h"
#include "parseconf.h"
#include "ftpproto.h"
#include "ftpcodes.h"
#include "hash.h"


unsigned int handle_ip_count(void *ip);
extern session_t *p_sess;
static unsigned int s_children;
void handle_sigchld(int sig);

static hash_t *s_ip_count_hash;
static hash_t *s_pid_ip_hash;

void check_limits(session_t *sess);
unsigned int hash_func(unsigned int buckets,void* key);
void drop_ip_count(void *ip);

int main(){
    //list_common();
    //exit(EXIT_SUCCESS);

    //char *str1 = "      a b";
    //char *str2 = "                    ";

    //if(str_all_space(str1))
    //    printf("str1 all space\n");
    //else
    //    printf("str1 not all space\n");

    //if(str_all_space(str2))
    //    printf("str2 all space\n");
    //else
    //    printf("str2 not all space\n");

    //if(getuid()!=0){
    //    fprintf(stderr,"miniftp:must be started as root\n");
    //    exit(EXIT_FAILURE);
    //}

    ////char *str3 = "abcDef";
    //char str3[] = "abcDef";
    //str_upper(str3);
    //printf("str3=%s\n",str3);

    //int n = str_octal_to_uint("0701");
    //printf("n = %d\n",n);

    //long long result = str_to_longlong("12345678901234");
    //printf("result = %lld\n",result);


    daemon(1,0);
    parseconf_load_file(MINIFTP_CONF);

    printf("tunable_pasv_enable=%d\n", tunable_pasv_enable);
    printf("tunable_port_enable=%d\n", tunable_port_enable);

    printf("tunable_listen_port=%u\n", tunable_listen_port);
    printf("tunable_max_clients=%u\n", tunable_max_clients);
    printf("tunable_max_per_ip=%u\n",   tunable_max_per_ip);
    printf("tunable_accept_timeout=%u\n", tunable_accept_timeout);
    printf("tunable_connect_timeout=%u\n", tunable_connect_timeout);
    printf("tunable_idle_session_timeout=%u\n", tunable_idle_session_timeout);
    printf("tunable_data_connection_timeout=%u\n", tunable_data_connection_timeout);
    printf("tunable_local_umask=0%o\n", tunable_local_umask);
    printf("tunable_upload_max_rate=%u\n", tunable_upload_max_rate);
    printf("tunable_download_max_rate=%u\n", tunable_download_max_rate);

    if (tunable_listen_address == NULL)
        printf("tunable_listen_address=NULL\n");
    else
        printf("tunable_listen_address=%s\n", tunable_listen_address);


    session_t sess={
        0,-1,
        "","","",
        NULL,-1,-1,0,
        0,0,0,0,
        -1,-1,
        0,0,NULL,0,
        0,0
    };

    p_sess = &sess;

    sess.bw_upload_rate_max = tunable_upload_max_rate;
    sess.bw_download_rate_max = tunable_download_max_rate;
    s_ip_count_hash = hash_alloc(256,hash_func);
    s_pid_ip_hash = hash_alloc(256,hash_func);

    signal(SIGCHLD,handle_sigchld);


    int listenfd = tcp_server(NULL,tunable_listen_port);
    int conn;
    pid_t pid;

    struct sockaddr_in addr;

    while(1){
        conn = accept_timeout(listenfd,&addr,0);
        if(conn == -1)
            ERR_EXIT("accept_timeout");
        unsigned int ip = addr.sin_addr.s_addr;
        ++s_children;
        sess.num_clients = s_children;
        sess.num_this_ip = handle_ip_count(&ip);
        pid = fork();
        if(pid == -1){
            --s_children;
            ERR_EXIT("fork");
        }
        if(pid == 0){
            close(listenfd);
            sess.ctrl_fd = conn;
            check_limits(&sess);
            signal(SIGCHLD,SIG_IGN);
            begin_session(&sess);
        }
        else{
            hash_add_entry(s_pid_ip_hash,&pid,sizeof(pid),&ip,sizeof(unsigned int));
            close(conn);
        }
    }
    return 0;
}

void check_limits(session_t *sess){
    if(tunable_max_clients > 0 && sess->num_clients > tunable_max_clients){
        ftp_relply(sess,FTP_TOO_MANY_USERS,"There are too many connected user,please try later.");
        exit(EXIT_FAILURE);
    }
    if(tunable_max_per_ip > 0 && sess->num_this_ip > tunable_max_per_ip){
        ftp_relply(sess,FTP_IP_LIMIT,"There are too many connected from your internet address.");
        exit(EXIT_FAILURE);
    }
}

void handle_sigchld(int sig){
    pid_t pid;
    while((pid = waitpid(-1,NULL,WNOHANG))>0){
        --s_children;
        unsigned int *ip = (unsigned int *)hash_lookup_entry(s_pid_ip_hash,&pid,sizeof(pid));
        if(ip == NULL){
            continue;
        }
        drop_ip_count(ip);
        hash_free_entry(s_pid_ip_hash,&pid,sizeof(pid));
    }
}

unsigned int hash_func(unsigned int buckets,void* key){
    unsigned int *number = (unsigned int*)key;
    return (*number)%buckets;
}

unsigned int handle_ip_count(void *ip){
    unsigned int count;
    unsigned int *p_count = (unsigned int*)hash_lookup_entry(s_ip_count_hash,ip,sizeof(unsigned int));
    if(p_count == NULL){
        count = 1;
        hash_add_entry(s_ip_count_hash,ip,sizeof(unsigned int),&count,sizeof(unsigned int));
    }
    else{
        count = *p_count;
        ++count;
        *p_count = count;
    }
    return count;
}

void drop_ip_count(void *ip){
    unsigned int count;
    unsigned int *p_count = (unsigned int*)hash_lookup_entry(s_ip_count_hash,ip,sizeof(unsigned int));
    if(p_count == NULL){
        return;
    }
    count = *p_count;
    if(count <= 0)
        return ;
    --count;
    *p_count = count;
    if(count == 0){
        hash_free_entry(s_ip_count_hash,ip,sizeof(unsigned int));
    }
}
