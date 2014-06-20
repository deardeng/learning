#include <iostream>
using namespace std;

class Base{
public:
	static int b_;
};
int Base::b_=100;
class Derived:public Base{
	
};
int main(void){
	Base b;
	Derived d;
	cout << Base::b_ << endl;
	cout << b.b_ << endl;

	cout << Derived::b_ << endl;
	cout << d.b_ << endl;
	return 0;
}