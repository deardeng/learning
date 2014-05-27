#include<curses.h>
int main(){
    WINDOW *w;
    initscr();
    box(stdscr,0,0);
    w=derwin(stdscr,4,20,5,3);
    box(w,0,0);

    refresh();
    wrefresh(w);
    getch();
    endwin();
}
