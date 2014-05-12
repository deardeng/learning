#include <iostream>
using namespace std;
#include <string>
struct date{
	int year;
	int month;
	int day;
};
struct Person{
	string name;
	int age;
	bool gender;
	double salary;
	date birth;
	Person(){cout<<"创建Person对象在"<<this<<endl;age=88;}
	~Person(){cout<<"释放Person对象在"<<this<<endl;}
};
class autoptr{
	Person* p;
	static int cnt;
public:
	autoptr(Person* p):p(p){++cnt;}
	autoptr(const autoptr& a):p(a.p){++cnt;}
	~autoptr(){cout<<cnt<<':'<<endl;if(--cnt==0)delete p;}
	Person* operator->(){return p;}
	Person& operator*(){return *p;}
};
int autoptr::cnt = 0;
int main()
{
	autoptr a(new Person);//a.cnt==1
	autoptr b = a;//b.cnt==2
	autoptr c = a,d(a),e(b);//c.cnt==3,d.cnt==4,e.cnt==5
	a->name = "芙蓉";//a.operator->()->name
	(*b).birth.year = 1985;
	cout << c->age << endl;
	cout << (*d).name << endl;
	cout << e->birth.year << endl;
}
