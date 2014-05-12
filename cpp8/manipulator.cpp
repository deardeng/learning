#include <iostream>
using namespace std;
//自定义格式控制符
//无参的，可以是对象
class __HEXUB{
	friend ostream& operator<<(ostream& o, const __HEXUB& h)
	{
		return o << hex << uppercase << showbase;
	} 
};
const __HEXUB hexub=__HEXUB();
//无参的，也可以是函数
ostream& func(ostream& o)
{
	return o << dec << showpos;
}
//带参的，可以是类，也可以是对象或者函数
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
ostream类中：
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
