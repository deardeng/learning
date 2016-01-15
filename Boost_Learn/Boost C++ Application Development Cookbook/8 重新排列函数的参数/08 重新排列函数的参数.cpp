////һ������������������������ֻ��һ��������+���������ǽ�һ��ֵ����2��
////���û��bind�������ʹ�ú���������ʵ������
//#include <functional>
//#include <algorithm>
//#include <vector>
//class Number {};
//inline Number operator+(Number, Number);
//
////Your Code Start
//struct mul_2_func_obj :public std::unary_function<Number, Number>
//{
//	Number operator()(Number n1)const
//	{
//		return n1 + n1;
//	}
//};
//void mul_2_impl1(std::vector<Number>& values)
//{
//	std::for_each(values.begin(), values.end(), mul_2_func_obj());
//}
//
//int main()
//{
//	return 0;
//}

////ʹ��Boost.Bind�Ĵ��뽫������������
//#include<boost/bind.hpp>
//#include<functional>
//#include<vector>
//#include <algorithm>
//
////class Number {};
//void mul_2_impl2(std::vector<int>& values)
//{
//	std::for_each(values.begin(), values.end(), boost::bind(std::plus<int>(), _1, _1));
//
//}
//
//template <class T>
//void mul_2_impl3(std::vector<T>& values)
//{
//	std::for_each(values.begin(), values.end(), boost::bind(std::plus<T>(), _1, _1));
//}
//
//int main()
//{
//	return 0;
//}

//��һ�����ӣ��������࣬����ʹ��һЩ�������豸���豸�������Բ�ͬ�ĳ��̣�
//���������ṩ�˲�ͬ��API����������ֻ��һ����������watch��������һ������������

//class Device1 
//{
//private:
//	short temperature();
//	short wetness();
//	int illumination();
//	int atmospheric_pressure();
//	void wait_for_data();
//public:
//	template<class FuncT>
//	void watch(const FuncT& f)
//	{
//		for (;;)
//		{
//			wait_for_data();
//			f(
//				temperature(),
//				wetness(),
//				illumination(),
//				atmospheric_pressure()
//				);
//		}
//	}
//};
//
//class Device2
//{
//private:
//	short temperature();
//	short wetness();
//	int illumination();
//	int atmospheric_pressure();
//	void wait_for_data();
//public:
//	template<class FuncT>
//	void watch(const FuncT& f)
//	{
//		for (;;)
//		{
//			wait_for_data();
//			f(
//				wetness(),
//				temperature(),
//				atmospheric_pressure(),
//				illumination()
//				);
//		}
//	}
//};
//
////Device1::watch��Device2::watch�����Բ�ͬ��˳��ֵ���ݸ�����������
////����һЩ���ṩһ���������������籩������һ���籩�ķ����㹻��ʱ�׳��쳣��
//void detect_storm(int wetness, int temperature, int atmospheric_pressure);
//
////���������Ϊ�����豸���ṩһ���籩��⺯�������������ʹ��bind����ʵ�֡�
//Device1 d1;
////�����ĺ��������󽫰����غ��Դ��ݸ��������õĶ������
//d1.watch(boost::bind(&detect_storm, _2, _1, _4));
//...
//d2.watch(boost::bind(&detect_storm, _1, _2, _3));

//boost.bind���ṩ�����õ����ܣ���Ϊ����ʹ�ö�̬������麯������ʹ��C++11 lambda��������ʹ��ʱ��Ҳ�����õ�


//#include<boost/bind.hpp>
//#include<functional>
//#include<vector>
//#include <algorithm>
//template<class FuncT>
//void watch(const FuncT& f)
//{
//	f(10, std::string("String"));
//	f(10, "Char array");
//	f(10, 10);
//}
//
//struct templated_foo
//{
//	template<class T>
//	void operator()(T, int)const
//	{
//		//û��ʵ�֣�ֻ����ʾ�󶨺�����Ȼ��������ģ��
//	}
//};
//
//void check_templated_bind()
//{
//	//���ǿ���ֱ��ָ������������ķ�������
//	//����ʧ��ʱ��������
//	watch(boost::bind<void>(templated_foo(), _2, _1));
//}
//
//int main()
//{
//	return 0;
//}

#include<boost/bind.hpp>
#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>

class Number {};
inline Number operator+(Number, Number)
{
	return Number();
}

struct mul_2_func_obj:public std::unary_function<Number, Number>
{
	Number operator()(Number n1) const
	{
		return n1 + n1;
	}
};

void mul_2_impl1(std::vector<Number>& values)
{
	std::for_each(values.begin(), values.end(), mul_2_func_obj());
}

void mul_2_impl2(std::vector<Number>& values)
{
	std::for_each(values.begin(), values.end(), boost::bind(std::plus<Number>(), _1, _1));
}

template<class T>
void mul_2_impl3(std::vector<T>& values)
{
	std::for_each(values.begin(), values.end(), boost::bind(std::plus<T>(), _1, _1));
}

class Device1
{
private:
	short temperature();
	short wetness();
	int illumination();
	int atmospheric_pressure();
	void wait_for_data();
public:
	template<class FuncT>
	void watch(const FuncT& f)
	{
		for (;;)
		{
			wait_for_data();
			f(
				temperature(),
				wetness(),
				illumination(),
				atmospheric_pressure()
				);
		}
	}
};

class Device2
{
private:
	short temperature();
	short wetness();
	int illumination();
	int atmospheric_pressure();
	void wait_for_data();
public:
	template<class FuncT>
	void watch(const FuncT& f)
	{
		for (;;)
		{
			wait_for_data();
			f(
				wetness(),
				temperature(),
				atmospheric_pressure(),
				illumination()
				);
		}
	}
};

void detect_storm(int wetness, int temperature, int atmospheric_pressure);

#include<assert.h>

struct storm_exception : std::exception {};

void detect_storm(int wetness, int temperature, int atmospheric_pressure)
{
	if (wetness == 2 && temperature == 1 && atmospheric_pressure == 4)
		throw storm_exception();
}

short Device1::temperature() { return 1; }
short Device1::wetness() { return 2; }
int Device1::illumination() { return 3; }
int Device1::atmospheric_pressure() { return 4; }
void Device1::wait_for_data()
{
	static int counter = 0;
	if (counter)
	{
		assert(false);
	}
	++counter;
}

short Device2::temperature() { return 1; }
short Device2::wetness() { return 2; }
int Device2::illumination() { return 3; }
int Device2::atmospheric_pressure() { return 4; }
void Device2::wait_for_data()
{
	static int counter = 0;
	if (counter)
	{
		assert(false);
	}
	++counter;
}

#include<string>

template <class FuncT>
void watch(const FuncT& f)
{
	f(10, std::string("String"));
	f(10, "Char array");
	f(10, 10);
}

struct templated_foo
{
	template<class T>
	void operator()(T, int) const
	{
	}
};

void check_templated_bind()
{
	watch(boost::bind<void>(templated_foo(), _2, _1));
}

int main()
{
	std::vector<Number> vec(10);
	mul_2_impl1(vec);
	mul_2_impl2(vec);
	mul_2_impl3(vec);

	try
	{
		try
		{
			Device1 d1;
			d1.watch(boost::bind(&detect_storm, _2, _1, _4));
		}
		catch (const storm_exception&)
		{
			std::cout << "device1 find storm\n";
		}
		try
		{
			Device2 d2;
			d2.watch(boost::bind(&detect_storm, _1, _2, _3));
		}
		catch (const storm_exception&)
		{
			std::cout << "device2 find storm\n";
		}
	}
	catch (...)
	{
		assert(false);
	}

	check_templated_bind();
	system("pause");
	return 0;
}