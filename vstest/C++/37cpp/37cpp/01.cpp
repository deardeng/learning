#include <iostream>
using namespace std;

class BB{
public:
	virtual void vfbb(){
		cout << "BB::vfbb" << endl;
	}
	virtual void vfbb2(){
		cout << "BB::vfbb2" << endl;
	}
	int bb_;
};
class B1:virtual public BB{
public:
	virtual void vfb1(){
		cout << "B1::vfb1" << endl;
	}
	int b1_;
};
class B2:virtual public BB{
public:
	virtual void vfb2(){
		cout << "B2::vfb2" << endl;
	}
	int b2_;
};
class DD:public B1,public B2{
public:
	virtual void vfdd(){
		cout << "DD::vfdd" << endl;
	}
	int dd_;
};
typedef void (*FUNC)();
int main(void){
	cout << sizeof(BB) << endl;
	cout << sizeof(B1) << endl;
	cout << sizeof(DD) << endl;
	
	BB bb;
	long **p;
	p=(long **)&bb;
	FUNC fun;
	fun = (FUNC)p[0][0];
	fun();
	fun = (FUNC)p[0][1];
	fun();
	cout << endl;
	B1 b1;
	
	

	p=(long**)&b1;
	fun = (FUNC)p[0][0];
	fun();
	fun = (FUNC)p[3][0];
	fun();
	fun = (FUNC)p[3][1];
	fun();
	cout << p[1][0] << endl;
	cout << p[1][1] << endl;
	cout << endl;



	DD dd;
	p=(long**)&dd;
	fun = (FUNC)p[0][0];
	fun();
	fun = (FUNC)p[3][0];
	fun();
	fun = (FUNC)p[7][0];
	fun();
	fun = (FUNC)p[7][1];
	fun();
	
	cout << p[1][0] << endl;
	cout << p[1][1] << endl;
	cout << endl;
	cout << p[4][0] << endl;
	cout << p[4][1] << endl;
	
	//BB *pp;
	//pp=&dd;
	//pp->bb_;//通过间接访问，需要运行时支持
	//


	return 0;
}