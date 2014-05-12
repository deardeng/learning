#include <iostream>
using namespace std;
class A{
	double d;
};
class B : public A{
	double d;
public:
	void f(){}
};
class C{
	double d;
public:
	virtual void f(){cout<<"C����麯��"<<endl;}
	virtual void g(){cout<<this<<",&d="<<&d<<endl;}
};
class D : public C{
	double d;
public:
	virtual void f(){cout<<"D����麯��"<<endl;}
	virtual void g(){}
	virtual void h(){}
	virtual void i(){}
	virtual void j(){}
};
int main()
{
	A* p = new B;
	C* q1 = new C, * q2 = new D;
	q1->f(); q2->f();
	q1->g();
	memcpy(q2,q1,4);//��q2��ָ��������ָ��ָ��C���麯����
	q2->f();
	delete p;
	delete q1; delete q2;
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
}
