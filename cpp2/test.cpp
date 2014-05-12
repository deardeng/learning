#include <iostream>
using namespace std;

int f(int a){return a*a;}
int f(int a, int b){return a*b;}
int main()
{
	cout << f(10) << endl;
	cout << f(12,34) << endl;
}

