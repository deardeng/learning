#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
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
#include <boost/cstdint.hpp>
#include <limits>
#define BOOST_SYSTEM_NO_LIB
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
using namespace boost::system;


int main()
{
	try
	{
		throw system_error(error_code(5, system_category()));
	}
	catch (system_error& e)
	{
		std::cout << e.what();
	}

}