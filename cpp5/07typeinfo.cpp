#include <iostream>
using namespace std;
#include <typeinfo>
class A{
	public:
		virtual void f(){}
};
class B : public A{};
class C : public B{};
class DDV : public A{};
int main()
{
	A*p1=new A,*p2=new B,*p3=new C,*p4=new DDV,*p5=new B; 
	cout << typeid(*p2).name() << endl;
	cout << typeid(*p3).name() << endl;
	cout << (typeid(*p2)==typeid(*p5)) << endl;
//	cout << typeid(*p2).before(typeid(*p1)) << endl;
//	cout << typeid(*p2).before(typeid(*p3)) << endl;
	cout << (typeid(*p1)!=typeid(*p2)) << endl;
	const type_info& t = typeid(*p4);
	cout << t.name() << endl;
	delete p1;delete p2;delete p3;delete p4;delete p5;
}
