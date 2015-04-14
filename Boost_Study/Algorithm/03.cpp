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
using namespace boost;

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

int main()
{
	using namespace boost::assign;
	array<int, 5> ar = (list_of(1), 2, 3, 4, 5);
	foreach(int x, ar)
		std::cout << x << " ";
	std::cout << std::endl;

	std::pair<array<int, 5>::iterator, array<int, 5>::iterator>
		rng(ar.begin(), ar.end() - 2);
	foreach(int x, rng)
		std::cout << x << " ";
	std::cout << std::endl;
	

	circular_buffer<int> cb = list_of(1) (2) (3);
	foreach(int x, cb)
		std::cout << x << " ";
	std::cout << std::endl;

	unordered_set<double> us = list_of(3.14) (2.717) (0.618);
	foreach(double x, us)
		std::cout << x << " ";
	std::cout << std::endl;
}
