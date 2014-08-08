#include <iostream>
using namespace std;

class BB{
public:
	int bb_;
};
class B1:virtual public BB{
public:
	int b1_;
};
class B2:virtual public BB{
public:
	int b2_;
};
class DD:public B1,public B2{
public:
	int dd_;
};
int main(void){
	cout << sizeof(BB) << endl;
	cout << sizeof(B1) << endl;
	cout << sizeof(DD) << endl;

	B1 b1;
	long **p;
	
	cout << &b1 << endl;
	cout << &b1.bb_ << endl;
	cout << &b1.b1_ << endl;
	p=(long**)&b1;
	cout << p[0][0] << endl;
	cout << p[0][1] << endl;

	DD dd;
	cout << &dd << endl;
	cout << &dd.bb_ << endl;
	cout << &dd.b1_ << endl;
	cout << &dd.b2_ << endl;
	cout << &dd.dd_ << endl;
	
	p=(long**)&dd;
	cout << p[0][0] << endl;
	cout << p[0][1] << endl;
	cout << endl;
	cout << p[2][0] << endl;
	cout << p[2][1] << endl;
	
	BB *pp;
	pp=&dd;
	//pp->bb_;//通过间接访问，需要运行时支持
	

	return 0;
}