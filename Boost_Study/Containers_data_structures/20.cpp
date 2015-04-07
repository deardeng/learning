#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/tuple/tuple.hpp>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/ref.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>

using namespace boost;

int main()
{
	struct demo
	{
		int x;
		double y;
		std::vector<std::string> str;
	};
	typedef tuple<int, double, std::vector<std::string> > t_type;
	assert(sizeof(demo) == sizeof(t_type));

	typedef tuple<int, std::string> my_tuple1;
	typedef tuple<int, my_tuple1> my_tuple2;
	assert(typeid(int) == typeid(tuples::element<0, my_tuple1>::type));
	assert(typeid(std::string) == typeid(tuples::element<1, my_tuple1>::type));
	std::cout << tuples::length<my_tuple2>::value << std::endl;


	int a = 10, b = 20;
	tie(a, b) = make_tuple(b, a);
	std::cout << "a = " << a << " " << "b = " << b << std::endl;
}