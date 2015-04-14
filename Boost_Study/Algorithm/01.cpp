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

int main()
{
	using namespace boost::assign;
	std::vector<int> v = (list_of(1), 2, 3, 4, 5);

	BOOST_FOREACH(int x, v)
	{
		std::cout << x << ",";
	}
	std::cout << std::endl;

	std::string str("boost foreach");
	BOOST_FOREACH(char& c, str)
	{
		std::cout << c << "-";
	}
	std::cout << std::endl;

	std::set<int> s = list_of(10) (20) (30);
	int xy;
	BOOST_FOREACH(xy, s);
	{
		//NOTE: question 怎么只打印一个30，不懂
		if (++xy % 7 != 0)
		{
			std::cout << xy << std::endl;
			//break;
		}
	}
	
	std::set<int> ss = list_of(10) (20) (30);
	BOOST_TYPEOF(*ss.begin()) y;
	BOOST_FOREACH(y, ss)
	{
		std::cout << y << std::endl;
	}
}
