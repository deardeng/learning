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
#include <boost/integer_traits.hpp>
#include <boost/cstdint.hpp>
#include <limits>
#include <boost/integer.hpp>
#include <boost/format.hpp>
using namespace boost;

int main()
{
	format fmt("type:%s, size=%dbit\n");

	uint_t<15>::fast a;
	std::cout << fmt % typeid(a).name() % (sizeof(a) * 8);

	int_max_value_t<32700>::fast b;
	std::cout << fmt % typeid(b).name() % (sizeof(b) * 8); 

	int_min_value_t<-33000>::fast c;
	std::cout << fmt % typeid(c).name() % (sizeof(c) * 8);

	uint_value_t<33000>::fast d;
	std::cout << fmt % typeid(d).name() % (sizeof(d) * 8);

	return 0;
}