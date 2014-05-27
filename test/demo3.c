#include<curses.h>

int main(){
    int ch;
    int x=5,y=5;
    initscr();
    keypad(stdscr,TRUE);
    noecho();
    mvaddch(y,x,'A');
    curs_set(0);
    while(1){
        ch=getch();
        clear();
       //mvaddch(y,x,' ');
        switch(ch){
            case KEY_UP:
                y--;
                break;
            case KEY_DOWN:
                y++;
                break;
            case KEY_LEFT:
                x--;
                break;
            case KEY_RIGHT:
                x++;
                break;
        }
        mvaddch(y,x,'A');
        refresh();
    }
    endwin();
}
