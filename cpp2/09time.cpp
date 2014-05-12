#include <iostream>
using namespace std;
#include <iomanip>
#include "09time.h"
Time::Time(int h, int m, int s)
{
	Time::h=h;
	Time::m=m;
	Time::s=s;
}
void Time::tick()
{
	if(++s>=60){
		s=0;
		if(++m>=60){
			m=0;
			if(++h>=24){
				h = 0;
			}
		}
	}
}
void Time::show()
{
	cout << setw(2) << setfill('0') << h << 
		':' << setw(2) << m << ':' << setw(2) << s << endl;
}

