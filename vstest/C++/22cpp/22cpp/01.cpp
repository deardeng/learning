#include "Complex.h"
//#include <iostream>
//using namespace std;
int main(void){
	Complex c1(3,5);
	Complex c2(4,6);

	//c1.Add(c2);
	//c1.Display();

	Complex c3=c1+c2;//等价于c1.operator(c2)或operator+(c1,c2)
	//Complex c3=c1.operator +(c2);
	c3.Display();
	return 0;
}