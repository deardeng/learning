#include <iostream>
using namespace std;

class F{
	int n;
	int d;
public:
	F(int n=0, int d=1);
	void print(bool newline=true);
	void print(bool newline=true)const;
	void input(){}
	~F();
};
void F::print(bool newline)const
{
	cout << "(只读的)" << n << '/' << d;
	if(newline) cout << endl;
}
F::~F()
{
	cout << this << ", ~F()" << n << '/' << d << endl;
}
F::F(int n, int d):n(n),d(d)//成员变量名(初始值)
{
	cout << this << ", F(" << n << ',' << d << ")\n";
}
void F::print(bool newline)
{
	cout << "(自由的)" << n << '/' << d;
	if(newline) cout << endl;
}
int compare(const F& x, const F& y)
{
	x.print(); y.print();
}
int main()
{
	F* q = static_cast<F*>(malloc(sizeof(F)));//不会调构造
	F a(1,2);
	F* p = new F;
	F b(3,4);
	a.print();
	delete p; p = NULL;
	b.print();
	free(q);//不会调析构函数
	q = new F[4];
	for(int i=0; i<4; i++) q[i].print(false);
	cout << endl;
	delete[] q;
	p = new F(8,15);
	delete p; p = NULL;
	const F c(5,6);
	c.print();
//	c.input();有const修饰的对象只能调用const成员函数
//	b.~F();
//	b.~F();
	cout << "====================" << endl;
	compare(a,b);
	cout << "====================" << endl;
}
