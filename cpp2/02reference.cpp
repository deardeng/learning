#include <iostream>
using namespace std;

int& max(int& x, int& y)
{
	return x<y?y:x;
}
int& counter()
{
	static int cnt=0;
	++cnt;
	return cnt;
}
int main()
{
	int m=10, n=20;
	max(m, n) += 80;
	cout << m << ',' << n << endl;
	counter() = 1000;
	cout << counter() << endl;
	cout << counter() << endl;
	cout << counter() << endl;
}

