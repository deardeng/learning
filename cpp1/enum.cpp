#include <iostream>
using namespace std;
#include <string>
enum Course{UNIX,C,CPP,UC,VC};
struct Student{
	string name;
	Course co;
};
enum Color{BLACK,RED,GREEN,YELLOW,BLUE,WHITE};
int main()
{
	Course c;
	Student s;
	int n;
	c = CPP;
	n = CPP;
	//c = n;//int --> Course
	Color clr=BLUE;
	//clr = VC;//Course --> Color
}

