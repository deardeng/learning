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

using namespace boost;

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

int main()
{
	using namespace boost::assign;
	
	int ar[] = { 1, 2, 3, 4, 5 };
	foreach(int& x, ar)
		std::cout << x << " ";
	std::cout << std::endl;

	std::map<int, std::string> m = map_list_of(1, "111") (2, "222") (3, "333");

	std::pair<int, std::string> x;
	foreach(x, m)
		std::cout << x.first << ':' << x.second << std::endl;

	std::vector< std::vector<int> > v = list_of(list_of(1)(2))(list_of(3)(4));
	foreach(std::vector<int>& row, v)
	{
		reverse_foreach(int &z, row)
			std::cout << z << ",";
		std::cout << std::endl;
	}
}
