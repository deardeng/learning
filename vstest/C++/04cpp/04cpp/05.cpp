#include<iostream>
using namespace std;
//不能返回局部变量的引用

int& add(int a,int b){
	int sum;
	sum=a+b;
	return sum;
}
int main(void){
	int n=add(3,4);
	int& n2 = add(5,6);//n2是引用，没有自己独立的地址空间
	//n2的值依赖于它所引用的变量。
	//如果n2所引用的变量的生命期结束了，也就是说n2
	//是一个无效的引用，那么n2的值将是不确定的。
	cout << "n2=" << n2 << endl;
	cout << "n=" << n << endl;
	cout << "n2=" << n2 << endl;
	return 0;
}