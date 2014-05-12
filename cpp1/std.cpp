#include <iostream>//input/output stream
#include <string>
int main()
{
	std::cout << "请输入您的姓名和年龄:\n";
	std::string name;
	int age;
	std::cin >> name >> age;
	std::cout << name << "您好，您出生于" << 2010-age << "年"
		<< std::endl;//end line==>'\n'
//	return 0;//main函数末尾的return 0可有可无
}

