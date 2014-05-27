#include<curses.h>
int main(){
    int ch;
    initscr();
    noecho();
    while(1){
        ch = mvgetch(5,10);
        mvprintw(8,10,"Your input was: %c(%d)",ch,ch);
    }
    endwin();
}
