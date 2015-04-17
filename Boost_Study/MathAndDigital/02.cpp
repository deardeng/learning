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
using namespace boost;

int main()
{
	int_fast_t<char>::fast a;
	std::cout << typeid(a).name() << std::endl;

	int_fast_t<int>::fast b;
	std::cout << typeid(b).name() << std::endl;

	int_fast_t<uint16_t>::fast c;
	std::cout << typeid(c).name() << std::endl;
	return 0;
}