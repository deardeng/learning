#include <iostream>
using namespace std;

inline void f1(){cout<<"call f1\n";}
inline int f2(int n){return n*n;}
inline int f3(int n){if(n<2)return 1;return n*f3(n-1);}
int main()
{
	f1();
	cout << f2(10) + f3(6) << endl;
}

