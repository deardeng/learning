#include <iostream>
#include <cstring>//string.h
using namespace std;
class A{
public:
	typedef unsigned int Uint;
private:
	int* p;
	Uint n;
public:
	A(Uint n):n(n){p=new int[n];if(p==NULL)throw 0;memset(p,0,n*4);}
	~A(){delete[] p;}
	Uint size()const{return n;}
	int& operator[](Uint i)const{if(i>=n)throw 1;return p[i];}
	int& operator[](const char* c)const{
		int i = atoi(c);
		if(i<0||i>=n)throw 1;
		return p[i];
	}
	void operator()(int v){for(Uint i=0; i<n; i++) p[i]=v;}
	void operator()(const char* s){
		int v = atoi(s);
		for(Uint i=0; i<n; i++) p[i]+=v;
	}
	int operator()(int beg, int delta){
		for(Uint i=0; i<n; i++) p[i]=beg,beg+=delta;
		return p[n-1];
	}
};
ostream& operator<<(ostream& o, const A& a)
{
	o << "{ ";
	for(int i=0; i<a.size(); i++)
		cout << a[i] << ' ';
	o << "}";
	return o;
}
class Chedan{
	typedef unsigned char uc;	
public:
	typedef string Uint;
	enum Color{RED,BLACK};
	struct Student{};
	class Teacher{};
};
int main()
{
	A x(5), y(8);
	x[2] = 20; y[6] = 66;//x.operator[](2); y.operator[](6)
	x["0"] = 8; y["2"] = 33;
	cout << "x=" << x << ", y=" << y << endl;
	x(3);//x.operator()(3)
	cout << "x=" << x << endl;
	y("50");
	cout << "y=" << y << endl;
	cout << "last element:" << x(10,2) << endl;//x.operator()(10,2)
	cout << "x=" << x << endl;
	cout << "last element:" << x(50,-1) << endl;//x.operator()(10,2)
	cout << "x=" << x << endl;
//	Chedan::uc c;к╫спЁит╠
	A::Uint m=123;
	Chedan::Uint s="hello";
	cout << m << ',' << s << endl;
	Chedan::Color clr=Chedan::RED;
	Chedan::Student stu;
	Chedan::Teacher t;
}
