#include <iostream>
using namespace std;

class F{
	int n;
	int d;
public:
	F(int n=0, int d=1):n(n),d(d){	}
	friend ostream& operator<<(ostream& o, const F& f){
		o << f.n << '/' << f.d;
		return o;
	}
	F& operator++(){n+=d;return *this;}
	F operator++(int){F old(*this);n+=d;return old;}
	friend F& operator--(F& f){f.n-=f.d;return f;}
	friend F operator--(F& f, int){F old(f);f.n-=f.d;return old;}
	operator double(){return 1.0*n/d;}
	operator bool(){return n!=0;}
};
void func1(F a){cout << a << endl;}
int main()
{
	F f1(2,5), f2(4,9), f3(17,3);
	cout << ++f1 << endl;//f1.operator++();
	cout << f2++ << endl;//f2.operator++(0);
	cout << "f1=" << f1 << ", f2=" << f2 << endl;
	cout << --f3 << endl;//operator--(f3)
	cout << f3-- << endl;//operator--(f3,0)
	cout << "f3=" << f3 << endl;
	cout << double(f1) << endl;//f1.operator double()
	cout << boolalpha <<(bool)f3 << endl;//f1.operator bool()
	cout << F(3) << endl;
	cout << (F)5 << endl;
	func1(6);
}
