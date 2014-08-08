#include <iostream>
using namespace std;

class Base{
public:
	Base():x_(0){

	}
	int GetBaseX()const{
		return x_;
	}
	void Show(){
		cout << "Base::Show..." << endl;
	}
	int x_;
};
class Derived:public Base{
public:
	Derived():x_(0){}
	int GetDerivedX()const{
		return x_;
	}
	void Show(int n){
		cout << "Derived::Show..." << n << endl;
	}
	void Show(){
		cout << "Derived::Show..."  << endl;
	}
	int x_;
};
class Test{
public:
	Base b_;
	int x_;
};
int main(void){
	Derived d;
	d.x_=10;
	d.Base::x_=20;
	cout << d.GetBaseX() << endl;
	cout << d.GetDerivedX() << endl;
	d.Base::Show();
	d.Show();
	cout << sizeof(Derived) << endl;
	cout << sizeof(Test) << endl;
	return 0;
}