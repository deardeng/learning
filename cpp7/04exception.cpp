#include <iostream>
using namespace std;
#include <exception>
class MyType{};
class MyException : public exception
{
public:
	const char* what()const throw(){return "我的芙蓉花";}
};
void f()throw(double,int,const char*,MyType,MyException)
{
	cout << "请输入一个1～5的整数:";
	int n;
	cin >> n;
	if(n==1)throw MyException();
	if(n==2)throw MyType();
	if(n==3)throw "hello";
	if(n==4)throw 123;
	if(n==5)throw 123.45;
	cout << "=====the end of f()=====" << endl;
}
class ME : public exception
{
	char msg[100];
public:
	ME(int n){sprintf(msg,"从第%d行抛出异常",n);}
	const char*what()const throw(){return msg;}
};
void g(){
	try{		f();	}
	catch(const char* e){cout<<"const char*"<<e<<endl;}
	catch(double e){cout<<"double"<<e<<endl;throw;}
	catch(MyException&e){cout<<"MyException"<<e.what()<<endl;}
	catch(exception&e){cout<<"exception:"<<e.what()<<endl;}
	catch(...){cout<<"g:其它异常"<<endl;throw ME(__LINE__);}
	cout << "=====the end of g()=====" << endl;
}
int main()
{
	try{		g();	}
	catch(exception&e){cout<<"main:"<<e.what()<<endl;}
	catch(...){cout<<"main:其它异常"<<endl;}
	cout << "=====the end of main()=====" << endl;
}
