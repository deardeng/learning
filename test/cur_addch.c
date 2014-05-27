#include<curses.h>
int main(){

    initscr();
    if(has_colors()==TRUE){
        start_color();
        init_pair(1,COLOR_RED,COLOR_WHITE);
        init_pair(2,COLOR_BLUE,COLOR_GREEN);
        init_pair(3,COLOR_BLACK,COLOR_WHITE);
        bkgd(COLOR_PAIR(3));
    }

    box(stdscr,0,0);
    mvaddch(2,10,ACS_PI|COLOR_PAIR(1));
    mvaddch(2,11,ACS_PI|COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
    mvaddstr(5,10,"Hello deardeng !");
    attroff(COLOR_PAIR(1));


    attron(COLOR_PAIR(2)|A_UNDERLINE);
    mvaddstr(8,10,"Hello deng !");
    attroff(COLOR_PAIR(2)|A_UNDERLINE);


    mvprintw(9,10,"line:%d,row:%d",LINES,COLS);

    //mvaddch(2,10,'A'|A_BOLD|A_UNDERLINE|A_BLINK);
    //mvaddch(2,11,'B'|A_DIM);
    //mvaddch(4,11,'C'|A_DIM);

    //addch(ACS_PI);
    //addch(ACS_STERLING);
    //addch(ACS_TTEE);
    //addch(ACS_S7);

    getch();
    endwin();
}
