#include <iostream>
using namespace std;

class F{
	int n;
	int d;
public:
	F(int n=0, int d=1);
	void print(bool newline=true);
	void input();
};
F::F(int n, int d):n(n),d(d)//成员变量名(初始值)
{
	cout << "F(" << n << ',' << d << ")\n";
}
void F::print(bool newline)
{
	cout << n << '/' << d;
	if(newline) cout << endl;
}
int main()
{
	F a(1,2), b(3,4);
	a.print();
	b.print();
}
