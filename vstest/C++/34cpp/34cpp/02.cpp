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
	Base(){
		cout << "Base..." << endl;
	}
	//如果一个类要作为多态基类，要将析构函数定义成虚函数
	virtual ~Base(){
		cout << "~Base..." << endl;
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
	Derived(){
		cout << "Derived..." << endl;
	}
	~Derived(){
		cout << "~Derived..." << endl;
	}
};
int main(void){
	Base* p;
	p=new Derived;
	p->Fun1();
	delete p;
	
	return 0;
}