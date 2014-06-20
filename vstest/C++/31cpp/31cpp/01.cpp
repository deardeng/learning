#include <iostream>
using namespace std;
#include <string>
class Employee{
public:
	Employee(const string& name,const int age,const int deptno)
		:name_(name),age_(age),deptno_(deptno){

	}
private:
	string name_;
	int age_;
	int deptno_;
};
class Manager:public Employee{
public:
	Manager(const string& name,const int age,const int deptno,int level)
		:Employee(name,age,deptno),level_(level){

	}
private:
	int level_;
};
class Manager2:private Employee{
public:
	Manager2(const string& name,const int age,const int deptno,int level)
		:Employee(name,age,deptno),level_(level){

	}
private:
	int level_;
};


int main(void){
	Employee e1("zhangsan",25,20);
	Manager m1("lisi",38,20,10);
	Manager2 m2("wangwu",38,15,8);
	Employee* pe;
	Manager* pm;
	Manager2* pm2;

	pe = &e1;
	pm = &m1;
	pm2 = &m2;

	pe=&m1;//派生类指针可以转换为基类指针。将派生类对象看成基类对象。
	//pm=&e1;//基类对象指针无法转化为派生类指针。无法将基类对象看成派生类对象。
	
	e1=m1;//派生类对象可以转换为基类对象。
	//将派生类对象看成基类对象
	//会产生对象切割（派生类特有成员消失）。
	//object slicing

	//pe = &m2;//私有或保护继承的时候，派生类指针不可以转换为基类指针，
	//pe = (Employee *)(pm2);
	pe = reinterpret_cast<Employee *>(pm2);

	//e1 = m2;//私有或保护继承的时候，派生类对象无法转换为基类对象。
	//e1 = reinterpret_cast<Employee >(m2);//私有或保护继承的时候，派生类对象无法转换为基类对象。
	
	pm2 = static_cast<Manager2*>(pe);//基类指针可以强制转化为派生类指针，但是不安全。
	//m1 = reinterpret_cast<Manager>(e1);//基类对象无法强制转化为派生类对象
	return 0;
}