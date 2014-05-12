#include <iostream>
using namespace std;
#include <cstdlib>
//static_cast数值类型之间，有一方是void*的指针类型之间
//const_cast用于临时去掉const、volatile限制
//reinterpret_cast任意两种指针类型之间，指针于数值类型之间
//dynamic_cast以后再讲
int main()
{
	int n = static_cast<int>(45.67);
	int* p = static_cast<int*>(calloc(sizeof(int),10));
	free(p);
	const int k = n;
	cout << "k=" << k << endl;
	const_cast<int&>(k) = 789;
	cout << "k=" << k << endl;
	float f=123.45;
	p = reinterpret_cast<int*>(&f);
	cout << *p << endl;
	n = int(12.34);
	cout << "n=" << n << endl;
	n = int();
	cout << "n=" << n << endl;
	int m(100);
	cout << "m=" << m << endl;
	int x();//函数声明
	int(y)=200;//尽量不用，容易跟强制类型转换混淆
	cout << "y=" << y << endl;
}
