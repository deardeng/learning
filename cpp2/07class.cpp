#include <iostream>
#include <string>
using namespace std;

struct PS{
	string name;
	int age;
	void show(){cout<<"����"<<name<<",����"<<age<<endl;}
};
class PC{
	string name;
	int age;
public:
	void show(){cout<<"����"<<name<<",����"<<age<<endl;}
	PC(const char* n,int a){name=n;age=a;}
};
int main()
{
	PS s={"ܽ��", 18};
	PC c("Ȩ��", 20);
	PC d;
	//d.name = "Ȩ��";//�������
	s.show();
	c.show();
}

