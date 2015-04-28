#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
using namespace boost;
using namespace boost::assign;

struct point
{
	int x, y;
	point(int a = 0, int b = 0) : x(a), y(b){}
	void print()
	{
		std::cout << "(" << x << "," << y << ")\n";
	}
};

struct demo
{
	int f(int a, int b)
	{
		return a + b;
	}
};

int g(int a, int b, int c)
{
	std::cout << "in g()" << "a = " << a << " b = " << b << " c = " << c << std::endl;
	return 0;
}

int main()
{
	demo a, &ra = a;
	demo *p = &a;

	std::cout << bind(&demo::f, a, _1, 20)(10) << std::endl;
	std::cout << bind(&demo::f, ra, _2, _1)(10, 20) << std::endl;
	std::cout << bind(&demo::f, p, _1, _2)(10, 20) << std::endl;

	std::vector<point> v(10);
	for_each(v.begin(), v.end(), bind(&point::print, _1));

	std::vector<point> v1(10);
	std::vector<int> v2(10);
	transform(v1.begin(), v1.end(), v2.begin(), bind(&point::x, _1));

	BOOST_FOREACH(int x, v2)
		std::cout << x << ",";
	std::cout << std::endl;
	typedef std::pair<int, std::string> pair_t;
	pair_t pp(123, "string");
	std::cout << bind(&pair_t::first, pp)() << std::endl;
	std::cout << bind(&pair_t::second, pp)() << std::endl;


	int xy = 10;
	std::cout << bind(g, _1, boost::cref(xy), boost::ref(xy))(110) << std::endl;
	//f fa;
	//std::cout << bind<int>(ref(af), _1, _2)(10, 20) << std::endl;
}