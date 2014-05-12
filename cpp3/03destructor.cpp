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
	cout << "(ֻ����)" << n << '/' << d;
	if(newline) cout << endl;
}
F::~F()
{
	cout << this << ", ~F()" << n << '/' << d << endl;
}
F::F(int n, int d):n(n),d(d)//��Ա������(��ʼֵ)
{
	cout << this << ", F(" << n << ',' << d << ")\n";
}
void F::print(bool newline)
{
	cout << "(���ɵ�)" << n << '/' << d;
	if(newline) cout << endl;
}
int compare(const F& x, const F& y)
{
	x.print(); y.print();
}
int main()
{
	F* q = static_cast<F*>(malloc(sizeof(F)));//���������
	F a(1,2);
	F* p = new F;
	F b(3,4);
	a.print();
	delete p; p = NULL;
	b.print();
	free(q);//�������������
	q = new F[4];
	for(int i=0; i<4; i++) q[i].print(false);
	cout << endl;
	delete[] q;
	p = new F(8,15);
	delete p; p = NULL;
	const F c(5,6);
	c.print();
//	c.input();��const���εĶ���ֻ�ܵ���const��Ա����
//	b.~F();
//	b.~F();
	cout << "====================" << endl;
	compare(a,b);
	cout << "====================" << endl;
}
