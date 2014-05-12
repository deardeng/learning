#include <iostream>
#include <string>
using namespace std;

struct PS{
	string name;
	int age;
	void show(){cout<<"我是"<<name<<",今年"<<age<<endl;}
};
class PC{
	string name;
	int age;
public:
	void show(){cout<<"我是"<<name<<",今年"<<age<<endl;}
	PC(const char* n,int a){name=n;age=a;}
};
int main()
{
	PS s={"芙蓉", 18};
	PC c("权哥", 20);
	PC d;
	//d.name = "权哥";//编译错误：
	s.show();
	c.show();
}

