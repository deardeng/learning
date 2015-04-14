#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <boost/variant.hpp>
using namespace boost;

typedef variant<int, double> var_tt;
void var_print(var_tt &v)
{
	if (v.type() == typeid(int))
	{
		get<int>(v) *= 2;
		std::cout << v << std::endl;
	}
	else if (v.type() == typeid(double))
	{
		get<double>(v) *= 2;
		std::cout << v << std::endl;
	}
	else
	{
		std::cout << "don't know type" << std::endl;
	}
}

int main()
{
	typedef variant<int, double, std::string> var_t;
	var_t v;
	assert(v.type() == typeid(int));
	assert(v.which() == 0);

	v = "variant demo";
	std::cout << *get<std::string>(&v) << std::endl;

	try
	{
		std::cout << get<double>(v) << std::endl;
	}
	catch (bad_get &)
	{
		std::cout << "bad_get" << std::endl;
	}

}