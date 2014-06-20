#include <iostream>
using namespace std;
class Test{
public:
	Test(int y):y_(y){

	}
	~Test(){

	}

	void TestFun(){
		cout << "x=" << x_ << endl;
		TestStaticFun();
	}
	static void TestStaticFun(){
		//TestFun(); Error,静态成员函数不能调用非静态成员函数 this指针
		cout << "TestStaticFun..." << endl;
		//cout << "y=" << y_ << endl;// Error 静态成员函数不能访问非静态成员
	}
	static int x_ ;//静态成员的引用性说明
	int y_;
};
int Test::x_=100;		//静态成员的定义性说明
int main(void){

	cout << sizeof(Test) << endl;
}