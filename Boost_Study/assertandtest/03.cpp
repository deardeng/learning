#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <boost/format.hpp>
#include <boost/static_assert.hpp>

template<typename T>
T my_min(T a, T b)
{
	BOOST_STATIC_ASSERT(sizeof(T) < sizeof(int));
	return a < b? a: b;
}

namespace my_space
{
	class empty_class
	{
		BOOST_STATIC_ASSERT(sizeof(int) >= 4);
	};

	BOOST_STATIC_ASSERT(sizeof(empty_class) == 1);
}

int main()
{
	BOOST_STATIC_ASSERT(2 == sizeof(short));
	BOOST_STATIC_ASSERT(true);
	BOOST_STATIC_ASSERT(16 == 0x10);

	std::cout << my_min((short)1, (short)3) << std::endl;
	//std::cout << my_min(1L, 3L);
}