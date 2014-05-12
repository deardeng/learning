#ifndef _CLOCK_H_
#define _CLOCK_H_
struct Time{
    int hour;
    int minute;
    int second;
};
void set(Time* p,int h,int m,int s);
void tick(Time* p);
void show(Time* p);
void run(Time* p);
#endif
