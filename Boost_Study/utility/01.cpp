#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/noncopyable.hpp>
#include <boost/utility.hpp>
#include <boost/typeof/typeof.hpp>

class do_not_copy : boost::noncopyable
{

};

std::vector<std::string> func()
{
	std::vector<std::string> v(10);
	return v;
}

int main()
{
	do_not_copy d1;
	do_not_copy d3;

	BOOST_TYPEOF(2.0*3) x = 2.0 * 3;
	BOOST_AUTO(y, 2+3);

	BOOST_AUTO(&a, new double[20]);
	BOOST_AUTO(p, std::make_pair(1, "string"));

	BOOST_AUTO(v, func());

}