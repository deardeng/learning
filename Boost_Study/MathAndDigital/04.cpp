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
	rational<int>a(3), b(65534), c(22,7);
	b += a;
	c -= a;
	if (c >= 0)
	{
		c = c * b;
		++a;
	}
	std::cout << "a = " << a << " b= " << b << " c= " << c << std::endl;
	assert(a == 4);
	
	rational<int> r(10);
	if (r)
	{
		r -= 10;
	}
	assert(!r);

	rational<int> r1(2718, 1000);
	std::cout << rational_cast<int>(r1) << std::endl;
	std::cout << rational_cast<double>(r1) << std::endl;

	//rational<int> r2;
	//std::cin >> r2;
	//std::cout << ++r2 << std::endl;

	rational<int> r3(22, 7);
	std::cout << r3.numerator() << " : " << r3.denominator()
		<< " = " << rational_cast<double>(r3) << std::endl;

	return 0;
}