#include<boost/any.hpp>
#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::vector<boost::any> some_values;
	some_values.push_back(10);
	const char* c_str = "Hello there!";
	some_values.push_back(c_str);
	some_values.push_back(std::string("Wow"));
	std::string& s = boost::any_cast<std::string&>(some_values.back());
	s += " That is great!\n";
	std::cout << s;

	//any��һ���յ�״̬���ҿ���ʹ��empty()��Ա�������

	boost::any variable(std::string("Hello world"));
	//#1:���������ʵ��ֵ����һ��std::string,���·������ܻ��׳�һ��boost::bad_any_cast�쳣
	std::string s1 = boost::any_cast<std::string>(variable);
	std::cout << s1 << std::endl;
	//#2:���������ʵ��ֵ����һ��std::string������һ��NULLָ��
	std::string* s2 = boost::any_cast<std::string>(&variable);
	std::cout << *s2 << std::endl;
	system("pause");
	return 0;
}