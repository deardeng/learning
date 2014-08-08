#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "builtin.h"
#include "parse.h"
#include "externs.h"
#include "init.h"
#include "execute.h"



void get_command(int i);

void getname(char *name);
void print_command();


void shell_loop(void){
    while(1){
        printf("[minishell]$ ");
        fflush(stdout);
        init();
        if( read_command() == -1)
            break;
        parse_command();
        print_command();
        execute_command();
    }
    printf("\nexit\n");
}

int read_command(void){
    if(fgets(cmdline,MAXLINE,stdin)==NULL){
        return -1;
    }
    return 0;
}

int parse_command(void){
    /*ls -l */
    //char *cp = cmdline;
    //char *avp = avline;
    //int i = 0;
    //while(*cp != '\0'){
    //    while(*cp == ' '||*cp == '\t')
    //        cp++;
    //    if(*cp == '\0'||*cp == '\n')
    //        break;
    //    cmd.args[i] = avp;

    //    while(*cp != '\0'&& *cp != ' ' && *cp != '\n')
    //        *avp++ = *cp++;

    //    *avp++ = '\0';
    //    printf("[%s]\n",cmd.args[i]);
    //    i++;
    //}


    /*cat < test.txt|grep -n public > test2.txt & */

	

	if(builtin()){
		return 0;
	}

    if(check("\n"))
        return 0;

    get_command(0);
    if(check("<"))
        getname(infile);

    int i;
    for(i=1;i<PIPELINE;++i){
        if(check("|"))
            get_command(i);
        else
            break;
    }

    if(check(">")){
        if(check(">"))
            append = 1;
        getname(outfile);
    }

    if(check("&"))
        backgnd = 1;

    if(check("\n")){
        cmd_count = i;
        return cmd_count;
    }
    else{
        fprintf(stderr,"Command line syntax error\n");
        return -1;
    }
    return 0;
}

int execute_command(void){
	execute_disk_command();
	return 0;
}

void get_command(int i){
    int j = 0;
    int inword = 0;
    while(*lineptr != '\0'){
        while(*lineptr == ' '||*lineptr == '\t')
            lineptr++;
        cmd[i].args[j] = avptr;
        while(*lineptr != '\0'
                && *lineptr != ' '
                && *lineptr != '\t'
                && *lineptr != '>'
                && *lineptr != '<'
                && *lineptr != '|'
                && *lineptr != '&'
                && *lineptr != '\n'){
            *avptr++ = *lineptr++;
            inword  = 1;
        }
        *avptr++ = '\0';

        switch(*lineptr){
            case ' ':
            case '\t':
                inword = 0;
                j++;
                break;
            case '>':
            case '<':
            case '|':
            case '&':
            case '\n':
                if(inword == 0)
                    cmd[i].args[j] = NULL;
                return;
            default: /* for '\0' */
                return;
        }
    }
}
int check(const char *str){
    char *p;
    while(*lineptr == ' '|| *lineptr == '\t')
        lineptr++;
    p = lineptr;
    while(*str!='\0'&&*str == *p){
        str++;
        p++;
    }

    if(*str == '\0'){
        lineptr = p;
        return 1;
    }
    return 0;
}
void getname(char *name){
    while(*lineptr == ' '|| *lineptr == '\t')
        lineptr++;
    while(*lineptr != '\0'
            && *lineptr != ' '
            && *lineptr != '\t'
            && *lineptr != '>'
            && *lineptr != '<'
            && *lineptr != '|'
            && *lineptr != '&'
            && *lineptr != '\n'){
        *name++ = *lineptr++;
    }
    *name = '\0';
}

void print_command(){
    int i;
    int j;
    printf("cmd_count = %d\n",cmd_count);
    if(infile[0]!='\0')
        printf("infile = [%s]\n",infile);
    if(outfile[0]!='\0')
        printf("outfile = [%s]\n",outfile);

    for(i=0;i<cmd_count;++i){
        j = 0;
        while(cmd[i].args[j]!=NULL){
            printf("[%s]",cmd[i].args[j]);
            j++;
        }
        printf("\n");
    }
}

