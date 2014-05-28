#include <iostream>
using namespace std;

class F{
    int n;
    int d;
    public:
    F(int n=0, int d=1);
    void print(bool newline=true);
    void print(bool newline=true)const;
    void input();
    ~F();
    F(const F& f):n(f.n),d(f.d)
    {cout<<this<<", F(F)"<<n<<'/'<<d<<endl;}
};
F::~F()
{	cout << this << ", ~F()" << n << '/' << d << endl;}
F::F(int n, int d):n(n),d(d)//成员变量名(初始值)
{	cout << this << ", F(" << n << ',' << d << ")\n";}
F func(F x){	return x;}
int main()
{
    F a(3,5);
    cout << "==================" << endl;
    func(a);
    cout << "==================" << endl;
    return 0;
}
