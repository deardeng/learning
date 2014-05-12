#include <iostream>
using namespace std;

class F{
	int n;
	int d;
	void reduce(){
		int mcd = maxcd(n<0?-n:n,d);
		if(mcd!=1) n/=mcd, d/=mcd;
	}
public:
	static int maxcd(int a, int b){
		if(a==0) return b;//静态成员函数中不能用this;
		return maxcd(b%a,a);
	}
	F(int n=0, int d=1):n(n),d(d){
		if(d==0) throw "分母不能为0";
		if(d<0) this->d=-d,F::n=-n;
		reduce();
//		cout << "F(" << n << '/' << d << ")\n";
	}
	friend ostream& operator<<(ostream& o, const F& f){
		o << f.n << '/' << f.d;
		return o;
	}
	friend F operator~(const F& f);
	bool operator!()const;
};
F operator~(const F& f)
{
	return F (f.d,f.n);
}
bool F::operator!()const
{
//	cout << *this << '(' << 1.0*n/d << ')' << endl;
	return !n;//(n==0);
}
int main()
{
	F f1(6,8);//3/4
	cout << "f1= " << f1 << endl;
	cout << "~f1=" << ~f1 << endl;//operator~(f1);
	cout << "f1= " << f1 << endl;
	cout << "!f1=" << !f1 << endl;//f1.operator!();
	//!f1;	!~f1;
}
