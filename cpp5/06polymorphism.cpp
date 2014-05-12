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
	virtual void show(){//�麯��
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
	void show(){//��д���Ը���ĳ�Ա���������Ը����Ǹ�ͬ����Ա
		cout << "ͬѧ�Ǻã�����" << course << "��ʦ" << name << "��ϣ���ܴ����Ұ�" << course << "�γ�ѧ��!(����)\n";
	}
};
int main()
{
	Person a("ܽ��",false);
	Teacher b("��ǿ",true,"UNIX C");
	Person* p=NULL, * q=NULL;
	p = &a; 
	q = &b;
	Person c=b;
	Person& d=b;
	p->show();
	q->show();
	c.show();
	d.show();
	cout << dynamic_cast<Teacher*>(p) << endl;
	cout << dynamic_cast<Teacher*>(q) << endl;
	cout << dynamic_cast<Teacher*>(&c) << endl;
	cout << dynamic_cast<Teacher*>(&d) << endl;
}
