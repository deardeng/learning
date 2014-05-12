#include"clock.h"
#include<iostream>
using namespace std;
#include<ctime>
void set(Time *p,int h,int m,int s){
    p->hour = h;
    p->minute=m;
    p->second=s;
}
void tick(Time* p){
    time_t t=time(NULL);
    while(time(NULL)==t);
    if(++p->second >= 60){
        p->second = 0;
        if(++p->minute >= 60){
            p->minute = 0;
            if(++p->hour >= 24)
                p->hour = 0;
        }
    }
}
void show(Time* p){
    cout << '\r';
    if(p->hour < 10)cout << 0;
    cout << p->hour << ':';
    if(p->minute < 10)cout << 0;
    cout << p->minute << ':';
    if(p->second < 10)cout << 0;
    cout << p->second << flush;
   // cout << endl;
}
void run(Time* p){
    for(;;){
        tick(p);
        show(p);
    }
}
