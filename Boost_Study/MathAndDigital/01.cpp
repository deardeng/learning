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
using namespace boost;

int main()
{
	std::cout << integer_traits<int>::const_max << std::endl;
	std::cout << integer_traits<bool>::const_min << std::endl;
	std::cout << integer_traits<long>::is_signed << std::endl;

	uint8_t u8;
	int_fast16_t i16;
	int_least32_t i32;
	uintmax_t um;

	u8 = 255;
	i16 = 32000;
	i32 = i16;
	um = u8 + i16 + i32;

	std::cout << typeid(u8).name() << ":" << sizeof(u8)
		<< " v= " << (short)u8 << std::endl;
	std::cout << typeid(i16).name() << ":" << sizeof(i16)
		<< " v= " << i16 << std::endl;
	std::cout << typeid(i32).name() << ":" << sizeof(i32)
		<< " v= " << i32 << std::endl;
	std::cout << typeid(um).name() << ":" << sizeof(um)
		<< " v= " << um << std::endl;

	std::cout << (short)std::numeric_limits<int8_t>::max() << std::endl;
	std::cout << std::numeric_limits<uint_least16_t>::max() << std::endl;
	std::cout << std::numeric_limits<int_fast32_t>::max() << std::endl;
	std::cout << std::numeric_limits<intmax_t>::max() << std::endl;
	std::cout << std::numeric_limits<intmax_t>::min() << std::endl;
	return 0;
}