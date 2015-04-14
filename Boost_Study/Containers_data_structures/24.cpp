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

int main()
{
	variant<int, float, std::string> v9;
	v9 = "123";

	typedef variant<int, double, std::string> var_t;
	var_t v(1);
	v = 2.13;
	var_t v2("string type");
	std::cout << get<std::string>(v2) << std::endl;
	v2 = v;

	assert(v.type() == typeid(double));

	std::cout << get<int>(var_t(108)) << std::endl;

}