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
#include <boost/crc.hpp>
using namespace boost;

int main()
{
	crc_32_type crc32;
	std::cout << std::hex;
	crc32.process_bytes("1234567890", 10);
	std::cout << crc32() << std::endl;

	std::string str = "1234567890";
	crc32.reset();

	std::cout << std::for_each(str.begin(), str.end(), crc32)() << std::endl;
	std::cout << crc32() << std::endl;

	std::cout << boost::crc<32, 0x8005, 0, 0, true, true>("1234567890", 10) << std::endl;

}