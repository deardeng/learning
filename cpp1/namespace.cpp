#include <iostream>
using namespace std;
#include <string>
namespace czq{
	string name="陈宗权";
	int age = 40;
}
namespace furong{
	char name[20]="芙蓉姐姐";
	double salary = 8000;
}
using namespace czq;
using namespace furong;
char name[20]="王磊";
int main()
{
	//cout << "我喜欢" << name << endl;//歧义：权哥？芙蓉？
	cout << "我是" << czq::name << ",今年" << age << endl;
	cout << "她是" << furong::name << ",月薪" << salary << endl;
	string name = "钟玉龙";
	cout << name << "很帅" << endl;//内部的name：钟玉龙
	cout << ::name << "也很帅" << endl;//全局的name：王磊
	return 0;
}

