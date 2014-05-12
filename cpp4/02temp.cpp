#include <iostream>
using namespace std;
class Teacher{
	string name;
	string course;
public:
	Teacher(const char* n, const char* c):name(n),course(c){
		cout << "创建" << course <<"老师" << name << endl;
	}
	Teacher(const Teacher& t):name(t.name),course(t.course){
		cout << "复制" << course <<"老师" << name << endl;
	}
	~Teacher(){
		cout << "辞退" << course <<"老师" << name << endl;
	}
};
int main()
{
	Teacher t1("陈宗权", "C++");
	Teacher t2=t1;//初始化
	Teacher t3=Teacher("杨强", "UC"); //用临时对象来初始化一个新对象，编译器一般会优化成直接用创建临时对象的参数来创建新对象
	t2 = t3;//赋值
	cout << "==================" << endl;
	t2 = Teacher("徐薇薇", "谘询");//赋值，临时对象会及时释放
	cout << "==================" << endl;
}
