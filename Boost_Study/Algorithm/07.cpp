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
#include <boost/algorithm/minmax_element.hpp>
using namespace boost;


int main()
{
	using namespace boost::assign;
	std::vector<int> v = (list_of(3), 5, 2, 2, 10, 9, 10, 8);
	std::vector<int>::iterator pos;
	pos = first_min_element(v.begin(), v.end());
	assert(pos - v.begin() == 2);
	pos = last_min_element(v.begin(), v.end());
	assert(pos - v.begin() == 3);
	BOOST_AUTO(x, first_min_last_max_element(v.begin(), v.end()));

	assert(x.first - v.begin() == 2 && x.second - v.begin() == 6);
}
