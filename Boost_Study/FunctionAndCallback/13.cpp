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

int f(int a, int b)
{
	return a + b;
}

struct demo_class
{
	int add(int a, int b)
	{
		return a + b;
	}
	int operator()(int x) const
	{
		return x * x;
	}
};

int main()
{
	function<int(int, int)> func(f);
	assert(func == f);
	if (func)
	{
		std::cout << func(10, 20) << std::endl;
	}

	func = 0;
	assert(func.empty());

	function<int(demo_class&, int, int)> func1;
	func1 = bind(&demo_class::add, _1, _2, _3);
	demo_class sc;
	std::cout << func1(sc, 10, 20) << std::endl;

	function<int(int, int)> func2;
	func2 = bind(&demo_class::add, sc, _1, _2);
	std::cout << func2(10, 20) << std::endl;

	demo_class scc;
	function<int(int)> funcc;
	funcc = cref(scc);
	std::cout << funcc(10) << std::endl;
}