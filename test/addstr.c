#include<curses.h>

int main(){
    char name[9]={0};
    initscr();

    mvaddstr(4,10,"user:[       ]");

    mvgetnstr(4,16,name,8);
    //name[r]=0;
    mvprintw(7,10,"Your input was:%s",name);
    refresh();
    getch();
    endwin();
}
