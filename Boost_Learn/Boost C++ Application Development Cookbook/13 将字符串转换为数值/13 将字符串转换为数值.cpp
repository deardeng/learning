#include<sstream>
#include<iostream>
void foo1()
{
	//�����ڣ�'iss'������һֱ��Ϊ����ֱ���������ĩβ
	//��ò�Ҫȥ������Щ�����ڼ䣬�ж��ٲ���Ҫ�Ĳ��������⺯�����ú��ڴ���䷢����
	std::istringstream iss("100");
	int i;
	iss >> i;
	std::cout << i << std::endl;
}

#include<cstdlib>
void foo2()
{
	//���е�ֵ����ת��Ϊint�ˣ�
	//�������м��ĳ��ֹͣ�ˣ�
	//��������'end'���������Ϊ����
	//˳��˵һ�£�������Ҫһ����������strtol����long int...
	//ת�����ֵ��������int����
	char* end;
	int i = std::strtol("100", &end, 10);
	printf("%d\n", i);
}

#include<boost/lexical_cast.hpp>

void foo3()
{
	int i = boost::lexical_cast<int>("100");
	(void)i;//Supressing warning about unused variable

	char chars[] = { '1', '0', '0' };
	int ii = boost::lexical_cast<int>(chars, 3);
	assert(ii == 100);

	try
	{
		//��x86�У�shortͨ�����ܴ洢����32767��ֵ
		short s = boost::lexical_cast<short>("1000000");
		assert(false);//�����ܵ�������
		(void)s;//Supressing warning about unused variable
	}
	catch (const boost::bad_lexical_cast& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		int i = boost::lexical_cast<int>("This is not a number!");
		assert(false);
		(void)i;//�����й�δʹ�õı����ľ���
	}
	catch (const boost::bad_lexical_cast& e)
	{
		std::cout << e.what() << std::endl;
	}
}

#include<locale>

//lexical_cast����ʹ��std::locale
void foo4()
{
	try
	{
		std::locale::global(std::locale("ru_RU.UTF8"));
		//�ڶ������ö�����ΪС���㣨�ָ�����
		float f = boost::lexical_cast<float>("1,0");
		assert(f < 1.01 && f > 0.99);
		std::locale::global(std::locale::classic());// Restoring C locale
	}
	catch (...)
	{
		//�˴�locale���쳣����֪��why������δ˵
	}
}

#include<algorithm>
#include<vector>
#include<iterator>
#include<boost/lexical_cast.hpp>

template <class ContainerT>
std::vector<long int> container_to_longs(const ContainerT& container)
{
	typedef typename ContainerT::value_type value_type;
	std::vector<long int> ret;
	typedef long int(*func_t)(const value_type&);
	func_t f = &boost::lexical_cast<long int, value_type>;
	std::transform(container.begin(), container.end(), std::back_inserter(ret), f);
	return ret;
}

#include <set>
#include <deque>
#include <string>
#include <boost/array.hpp>

void foo5()
{
	std::set<std::string> str_set;
	str_set.insert("1");
	assert(container_to_longs(str_set).front() == 1);

	std::deque<const char*> char_deque;
	char_deque.push_front("1");
	char_deque.push_back("2");
	assert(container_to_longs(char_deque).front() == 1);
	assert(container_to_longs(char_deque).back() == 2);


	typedef boost::array<unsigned char, 2> element_t;//array��array
	boost::array<element_t, 2> arrays = { {{{'1','0'}},{{'2','0'}}} };
	assert(container_to_longs(arrays).front() == 10);
	std::vector<long int> ret = std::move(container_to_longs(arrays));
	assert(container_to_longs(arrays).back() == 20);
	assert(ret.back() == 20);
}

int main()
{
	foo1();
	foo2();
	foo3();
	foo4();
	foo5();

	system("pause");
	return 0;
}