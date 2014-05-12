#include <iostream>
using namespace std;
#include <string>
class Person{
protected:
	string name;
private:
	bool gender;
public:
	void eat(const char* food)
	{cout<<name<<"�ڳ�"<<food<<endl;}
	void sleep();
	void show(){
		cout << "��Һã�����" << (gender?"˧��":"��Ů") << name << "����������ʶ��!" << endl;
	}
	Person(const char* name, bool gender)
	:name(name),gender(gender){}
	string Name()const{return name;}
};
class Teacher : public Person
{
	string course;
public:
	void teach(const char* _class){
		cout << name << "��ʦ�ڸ�" << _class << "�ི" << course << "�γ�" << endl;
	}
	Teacher(const char* name, bool gender, const char* course)
	:Person(name,gender),course(course){}
	void show(const char* _class){//��д���Ը���ĳ�Ա���������Ը����Ǹ�ͬ����Ա
		cout << _class << "���" << "ͬѧ�Ǻã�����" << course << "��ʦ" << name << "��ϣ���ܴ����Ұ�" << course << "�γ�ѧ��!(����)\n";
	}
};
int main()
{
	Person a("ܽ��",false);
	Teacher b("��ǿ",true,"UNIX C");
	a.eat("�ɿ���");
	b.eat("�ݽ���צ");
	a.show();
	b.show("csd1007");
	b.Person::show();
	b.teach("csd1007");
//	cout << b.name << endl;������Ա������������
//	cout << a.name << endl;������Ա������������
	cout << a.Name() << endl;
	cout << b.Name() << endl;
}
