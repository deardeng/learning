#include <iostream>
using namespace std;

class Base{
public:
	virtual void Fun1(){
		cout << "Base::Fun1..." << endl;
	}
	virtual void Fun2(){
		cout << "Base::Fun2..." << endl;
	}
	int data1_;
};
class Derived:public Base{
public:
	void Fun2(){
		cout << "Derived::Fun2..." << endl;
	}
	virtual void Fun3(){
		cout << "Derived::Fun3..." << endl;
	}
	int data2_;
};
typedef void (*FUNC)();
int main(void){
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;
	Base b;
	long **p=(long**)&b;
	FUNC fun=(FUNC)p[0][0];
	fun();
	fun=(FUNC)p[0][1];
	fun();

	cout << endl;
	Derived d;
	p=(long**)&d;
	fun=(FUNC)p[0][0];
	fun();
	fun=(FUNC)p[0][1];
	fun();
	fun=(FUNC)p[0][2];
	fun();


	Base* pp=&d;
	pp->Fun2();
	return 0;
}