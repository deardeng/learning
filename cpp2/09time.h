#ifndef TIME_H
#define TIME_H 1
class Time{
	int h, m, s;
public:
	Time(){h=m=s=0;}
	Time(int h, int m, int s);
	void tick();
	void show();
};
#endif

