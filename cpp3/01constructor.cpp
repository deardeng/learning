#include <iostream>
using namespace std;
#include <string>
class Person{
	string name;
	bool gender;
	int age;
	Person* lover;
public:
	Person(const char* n="无名", bool g=true);
	void growup(int years);
	void show();
	void marry(Person& oth);
};
void Person::marry(Person& oth)
{
	lover = &oth;
	oth.lover = this;
	cout << name << "和" << oth.name << "喜结良缘\n"; 
}
Person::Person(const char* name, bool gender)
{
	cout << name << "出生了，大家去领红包" << endl;
	(*this).name = name;
	this->gender = gender;
	age = 0;
	lover = NULL;
}
void Person::growup(int years)
{
	age += years;
}
void Person::show()
{
	cout << "大家好，我是" << (gender?"帅哥":"美女") << name << "，今年" << age << "岁。";
	if(lover==NULL)
		cout << "目前单身贵族。" << endl;
	else
		cout << "爱人是" << lover->name << "。" << endl;
}
int main()
{
	Person a("芙蓉",false);
	Person b("杨强",true);
	Person c("二狗");
	Person d;
	Person e();//声明一个函数e
	a.growup(18);//growup(&a,18); lea ECX, b
	b.growup(20);//growup(&b,20); lea ECX, b
	a.show();
	b.show();
	c.growup(5);
	d.growup(25);
	c.show();
	d.show();
	//e.growup(3);不能把e当成对象
//	e().show();
	b.marry(a);
	a.show();
	b.show();
}
Person e()
{
	string name;
	bool gender;
	int age;
	cout << "请输入姓名、性别和年龄:";
	cin >> name >> gender >> age;
	Person input(name.c_str(), gender);
	input.growup(age);
	return input;
}
