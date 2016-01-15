#include<boost/variant.hpp>
#include<iostream>
#include<vector>
#include<string>

int main()
{
	typedef boost::variant<int, const char*, std::string> my_var_t;
	std::vector<my_var_t> some_values;
	some_values.push_back(10);
	some_values.push_back("Hello there!");
	some_values.push_back(std::string("Wow!"));
	std::string& s = boost::get<std::string>(some_values.back());
	s += " That is great!\n";
	std::cout << s << std::endl;


	//variantû�п�״̬,������һ��empty()�����������Ƿ���false(��)�����ȷʵ��Ҫ��ʾһ����״̬��
	//ֻ����boost.variant��֧�ֵ����͵Ŀ�ʼλ�����ĳ���򵥵����ͣ���variant����������ʱ����������Ϊһ����״̬��

	typedef boost::variant<boost::blank, int, const char*, std::string> my_var_tb;
	//Ĭ�Ϲ��캯������һ��boost::blankʵ��
	my_var_tb var;
	//'which()'��������һ��������е����͵�����
	assert(var.which() == 0);//��״̬
	var = "Hello, dear deng";
	assert(var.which() != 0);

	//����ʹ�����ַ�����һ������õ�һ��ֵ
	boost::variant<int, std::string> variable(0);
	//���������ʵ��ֵ����һ��int���ͣ�����ķ��������׳�boost::bad_get�쳣
	int s1 = boost::get<int>(variable);
	//���������ʵ��ֵ����һ��int���ͣ�������һ��NULLָ��
	int *s2 = boost::get<int>(&variable);

	system("pause");
	return 0;
}