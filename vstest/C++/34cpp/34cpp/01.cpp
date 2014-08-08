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
	void Fun3(){
		cout << "Base::Fun3..." << endl;
	}
};
class Derived:public Base{
public:
	/*virtual*/ void Fun1(){
		cout << "Derived::Fun1..." << endl;
	}
	/*virtual*/ void Fun2(){
		cout << "Derived::Fun2..." << endl;
	}
	void Fun3(){
		cout << "Derived::Fun3..." << endl;
	}
};
int main(void){
	Base *p;
	Derived d;
	p=&d;

	p->Fun1();	//Fun1是虚函数，基类之指针指向派生类对象，调用的是派生类对象的虚函数。
	p->Fun2();
	p->Fun3();	//Fun3非虚函数，根据p指针实际类型来调用相应类的成员函数。

	return 0;
}