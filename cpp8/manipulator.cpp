#include <iostream>
using namespace std;
//�Զ����ʽ���Ʒ�
//�޲εģ������Ƕ���
class __HEXUB{
	friend ostream& operator<<(ostream& o, const __HEXUB& h)
	{
		return o << hex << uppercase << showbase;
	} 
};
const __HEXUB hexub=__HEXUB();
//�޲εģ�Ҳ�����Ǻ���
ostream& func(ostream& o)
{
	return o << dec << showpos;
}
//���εģ��������࣬Ҳ�����Ƕ�����ߺ���
class wf{
	unsigned int w;
	char f;
public:
	wf(unsigned int w, char fill=' '):w(w),f(fill){}
	friend ostream& operator<<(ostream& o, const wf& x)
	{
		o.width(x.w);
		o.fill(x.f);
		return o;
	}
};
/*
ostream���У�
	ostream& operator<<( ostream& (*f)(ostream& o) )
	{
		return f(*this);
	}
*/
int main()
{
	cout << hexub << 123 << endl;//0X7B
	cout << wf(10,'*') << "good" << endl;
	cout << wf(8) << "good" << endl;
	cout << func << 123 << endl;//+123
}
