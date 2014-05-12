#include <iostream>
using namespace std;

class F{
	int n;
	int d;
public:
	F(int n=0, int d=1):n(n),d(d){}
	int getn()const{return n;}
	int getd()const{return d;}
	friend istream& operator>>(istream& in, F& f);//友元
};
istream& operator>>(istream& in, F& f)
{
	char c;
	in >> f.n >> c >> f.d;
	return in; 
}
ostream& operator<<(ostream& out, const F& f)
{
	out << "分子" << f.getn() << "分母" << f.getd();
	return out;
}
int main()
{
	F a, b;
	int n;
	cin >> a >> b;//cin.operator>>(a); operator>>(cin,a);
	cout<<a<<b;//cout.operator<<(a); operator<<(cout,a); 
}
