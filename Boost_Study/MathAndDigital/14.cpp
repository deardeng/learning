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
#include <boost/logic/tribool.hpp>
#include <boost/operators.hpp>
#include <boost/algorithm/minmax.hpp>
#include <boost/random.hpp>
#include <ctime>
#include <boost/serialization/singleton.hpp>
using namespace boost;


int main()
{
	mt19937 rng(time(0));

	uniform_int<> ui(0, 255);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << ui(rng) << ",";
	}
	std::cout << std::endl;

	uniform_01<mt19937&> u01(rng);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << u01() << ",";
	}
	std::cout << std::endl;

	normal_distribution<> nd(1, 2);
	int count = 0;
	for (int i = 0; i < 10000; ++i)
	{
		if (abs(nd(u01) - 1) <= 2.0)
		{
			++count;
		}
	}
	std::cout << 1.0 * count / 10000 << std::endl;
}