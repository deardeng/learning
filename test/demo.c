#include<curses.h>
#include<time.h>
#include<unistd.h>

void init();
void drawui();
void business();
void destroy();
int main(){
    init();
    drawui();
    business();
    destroy();
}

void init(){
    initscr();
}

void destroy(){
    endwin();
}

void drawui(){
    box(stdscr,0,0);
}

void business(){
    time_t tt;
    struct tm *t;
    while(1){
        tt=time(0);
        t=localtime(&tt);
        mvprintw(LINES/2,(COLS-8)/2,"%02d:%02d:%02d",t->tm_hour,t->tm_min,t->tm_sec);
        refresh();
        sleep(1);
    }
}
