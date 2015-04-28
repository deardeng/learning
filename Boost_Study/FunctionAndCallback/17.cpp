#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <boost/rational.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::assign;

class demo_class
{
private:
	typedef function<void(int)> func_t;
	func_t func;
	int n;
public:
	demo_class(int i) : n(i){}
	template<typename CallBack>
	void accept(CallBack f)
	{
		func = f;
	}
	void run()
	{
		func(n);
	}
};

class call_back_factory
{
public:
	void call_back_func1(int i)
	{
		std::cout << "call back factory1 : ";
		std::cout << i * 2 << std::endl;
	}
	void call_back_func2(int i, int j)
	{
		std::cout << "call back factory2 : ";
		std::cout << i * j * 2 << std::endl;
	}
};

int main()
{
	demo_class dc(10);
	call_back_factory cbf;
	dc.accept(bind(&call_back_factory::call_back_func1, cbf, _1));
	dc.run();
	dc.accept(bind(&call_back_factory::call_back_func2, cbf, _1, 5));
	dc.run();
}