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
	{cout<<name<<"在吃"<<food<<endl;}
	void sleep();
	void show(){
		cout << "大家好，我是" << (gender?"帅哥":"美女") << name << "，很荣幸认识你!" << endl;
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
		cout << name << "老师在给" << _class << "班讲" << course << "课程" << endl;
	}
	Teacher(const char* name, bool gender, const char* course)
	:Person(name,gender),course(course){}
	void show(const char* _class){//改写来自父类的成员，隐藏来自父类那个同名成员
		cout << _class << "班的" << "同学们好，我是" << course << "老师" << name << "，希望能带领大家把" << course << "课程学好!(掌声)\n";
	}
};
int main()
{
	Person a("芙蓉",false);
	Teacher b("杨强",true,"UNIX C");
	a.eat("巧克力");
	b.eat("泡椒凤爪");
	a.show();
	b.show("csd1007");
	b.Person::show();
	b.teach("csd1007");
//	cout << b.name << endl;保护成员不能在外界访问
//	cout << a.name << endl;保护成员不能在外界访问
	cout << a.Name() << endl;
	cout << b.Name() << endl;
}
