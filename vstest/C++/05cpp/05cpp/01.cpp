#include <iostream>
using namespace std;

//const_cast用来移除常量性
//const_cast一般来说用指针或者引用
//const_cast去除常量性不是为了修改它所指向的内容
//const_cast去除常量性是为了函数能接受实参
void fun(int &val){
	cout << "fun" << val << endl;
}
int main(void){
	const int val=100;
	//int n=const_cast<int> (val);
	int n=val; 
	int *p=const_cast<int*>(&val);
	*p=200;
	printf("val=%p\n",val);
	printf("p=%p\n",p);
	cout << &val << endl;
	cout << p << endl;
	cout << "val=" << val << endl;


	const int val2=200;
	int& refval2=const_cast<int&>(val2);
	refval2=300;
	cout << "val2=" << val2 <<  endl;

	fun(const_cast<int&>(val2));
 	return 0;
}