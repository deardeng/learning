#include <iostream>
using namespace std;
#include <iomanip>
class Time{
	int h, m, s;
public:
	Time(){h=m=s=0;}
	Time(int h, int m, int s){Time::h=h;Time::m=m;Time::s=s;}
	void tick(){
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
	void show(){
		cout << setw(2) << setfill('0') << h << ':' << setw(2) << m << ':' << setw(2) << s << endl;
	}
};
int main()
{
	Time t1;
	Time t2(16,49,58);
	t1.tick();
	t2.tick();
	t1.show();
	t2.show();
	return 0;
}

