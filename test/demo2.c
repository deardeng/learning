#include<curses.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
void init();
void drawLogin();
void destroy();
int main(){
    init();
    drawLogin();
    destroy();
}
void init(){
    initscr();
}
void destroy(){
    refresh();
    getch();
    endwin();
}
void drawLogin(){
    char *heads = "联通bbs业务员支撑系统";
    char *user = "user【        】";
    char *pass = "pass【        】";
    box(stdscr,0,0);
    mvaddstr(3,(COLS-strlen(heads))/2,heads);
    mvaddstr(6,(COLS-strlen(user))/2,user);
    mvaddstr(8,(COLS-strlen(pass))/2,pass);
    refresh();
}
