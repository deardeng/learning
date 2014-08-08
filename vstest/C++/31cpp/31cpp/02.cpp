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
	//从语法上来演示基类对象可以转化为派生对象，但是没有意义
	/*Manager(const Employee& other):Employee(other),level_(-1){
 
	}*/
private:
	int level_;
};

int main(void){
	Employee e1("zhangsan",25,20);
	Manager m1("lisi",38,20,10);
	
	m1=e1;

	return 0;
}