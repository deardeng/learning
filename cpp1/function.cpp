#include <iostream>
using namespace std;
void f1(){cout<<"hello"<<endl;return;}
void f2(void){return f1();}
void f3(double){cout<<"world"<<endl;}//�����������֣���Ԫ
int main()
{
	//f1(123);����f1���޲ε�
	f1();
	f2();
	f3(12.3);
}

