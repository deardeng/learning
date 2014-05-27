#include<curses.h>
void init();
void drawUi();
void dealInput();
void destroy();

int main(){
    init();
    drawUi();
    dealInput();
    destroy();
}

void init(){
    initscr();
}

void drawUi(){
    mvaddstr(2,2,"[    ]+[     ]=[      ]");
    refresh();
}

void destroy(){
    endwin();
}

void dealInput(){
    int a,b;
    while(1){
        mvaddstr(2,3,"    ");
        mvscanw(2,3,"%d",&a);
        mvaddstr(2,10,"     ");
        mvscanw(2,10,"%d",&b);
        mvaddstr(2,18,"      ");
        mvprintw(2,18,"%d",a+b);
        refresh();
    }
}

