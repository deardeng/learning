#include <iostream>
using namespace std;
void f1(){cout<<"hello"<<endl;return;}
void f2(void){return f1();}
void f3(double){cout<<"world"<<endl;}//有类型无名字：哑元
int main()
{
	//f1(123);函数f1是无参的
	f1();
	f2();
	f3(12.3);
}

