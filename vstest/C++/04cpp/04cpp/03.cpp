#include<iostream>
using namespace std;
//引用作为参数传递
void swap(int& x,int& y){
	int temp=x;
	x=y;
	y=temp;
}
int main(void){
	int a=5;
	int b=6;
	swap(a,b);
	cout << "a=" << a << "b=" << b << endl;
	//在函数调用时，引用被初始化 x=a,y=b;
	return 0;
}