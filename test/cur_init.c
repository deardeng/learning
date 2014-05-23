#include<curses.h>

int main(){
    initscr();
    //WINDOW *w=initscr();
    //border('a','b','c','d','e','f','g','h');
    //border(0,0,0,0,0,0,0,0);
    //box(stdscr,'$','*');
    box(stdscr,0,0);
    mvhline(2,10,'^',20);
    mvvline(2,10,'<',10);
    mvhline(12,10,'^',20);
    mvvline(2,30,'>',10);
    refresh();
    getch();
    endwin();
    return 0;
}
