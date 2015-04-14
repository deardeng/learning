#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <boost/multi_array.hpp>
#include <cstddef>
#include <stdexcept>
#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/unordered_set.hpp>
#include <boost/algorithm/minmax.hpp>
using namespace boost;


int main()
{
	std::cout << std::max(200, 12) << std::endl;
	std::cout << std::min(200, 12) << std::endl;

	BOOST_AUTO(x, minmax(11, 22));
	std::cout << x.get<1>() << " " << x.get<0>() << std::endl;

	std::string s1("5000"), s2("123");
	auto xy = std::minmax(s1, s2);
	std::cout << get<0>(xy) << " " << get<1>(xy) << std::endl;

	auto yz = std::minmax({ 3, 4, 8, 1 });
	std::cout << get<0>(yz) << " " << get<1>(yz) << std::endl;
}
