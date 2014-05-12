#include <iostream>
using namespace std;
#include <string>
class Person{
	string name;
	bool gender;
	int age;
	Person* lover;
public:
	Person(const char* n="����", bool g=true);
	void growup(int years);
	void show();
	void marry(Person& oth);
};
void Person::marry(Person& oth)
{
	lover = &oth;
	oth.lover = this;
	cout << name << "��" << oth.name << "ϲ����Ե\n"; 
}
Person::Person(const char* name, bool gender)
{
	cout << name << "�����ˣ����ȥ����" << endl;
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
	cout << "��Һã�����" << (gender?"˧��":"��Ů") << name << "������" << age << "�ꡣ";
	if(lover==NULL)
		cout << "Ŀǰ������塣" << endl;
	else
		cout << "������" << lover->name << "��" << endl;
}
int main()
{
	Person a("ܽ��",false);
	Person b("��ǿ",true);
	Person c("����");
	Person d;
	Person e();//����һ������e
	a.growup(18);//growup(&a,18); lea ECX, b
	b.growup(20);//growup(&b,20); lea ECX, b
	a.show();
	b.show();
	c.growup(5);
	d.growup(25);
	c.show();
	d.show();
	//e.growup(3);���ܰ�e���ɶ���
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
	cout << "�������������Ա������:";
	cin >> name >> gender >> age;
	Person input(name.c_str(), gender);
	input.growup(age);
	return input;
}
