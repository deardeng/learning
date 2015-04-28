#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::assign;

struct demo
{
	int f(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	demo a, &ra = a;
	demo *p = &a;

	std::cout << bind(&demo::f, a, _1, 20)(10) << std::endl;
	std::cout << bind(&demo::f, ra, _2, _1)(10, 20) << std::endl;
	std::cout << bind(&demo::f, p, _1, _2)(10, 20) << std::endl;
}