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
#include <boost/rational.hpp>
using namespace boost;

int main()
{
	rational<int> a(1414, 1000), pi(314, 100);
	std::cout << abs(a) << std::endl;
	std::cout << pow(rational_cast<double>(a), 2) << std::endl;
	std::cout << cos(rational_cast<double>(pi)) << std::endl;

	rational<int> e(22, 7), b;
	try
	{
		e / b;
	}
	catch (bad_rational& e)
	{
		std::cout << typeid(e).name() << e.what() << std::endl;
	}

	
	return 0;
}