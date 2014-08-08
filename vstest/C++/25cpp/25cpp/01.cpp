#include "Integer.h"
#include <iostream>
using namespace std;

int add(int a,int b){
	return a+b;
}
int main(void){
	Integer n(100);
	n=200;
	n.Display();

	int sum=add(n,100);
	cout << sum << endl;

	int x=n;
	cout << x << endl;
	int y=static_cast<int>(n);
	return 0;
}