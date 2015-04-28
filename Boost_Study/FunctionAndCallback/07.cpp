#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::assign;

int f(int a, int b)
{
	return a + b;
}

int g(int a, int b, int c)
{
	return a + b * c;
}

typedef int(*f_type) (int, int);
typedef int(*g_type) (int, int, int);

int main()
{
	std::cout << bind(f, 1, 2)() << std::endl;
	std::cout << bind(g, 1, 2, 3)() << std::endl;

	f_type pf = f;
	g_type pg = g;
	int x = 1, y = 2, z = 3;
	std::cout << bind(pf, _1, 9)(x) << std::endl;
	std::cout << bind(pg, _3, _2, _2)(x, y, z) << std::endl;
}