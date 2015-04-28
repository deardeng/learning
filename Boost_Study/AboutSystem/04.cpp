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
using namespace boost::system;

class my_category : public error_category
{
public:
	virtual const char* name() const
	{
		return "myapp_category";
	}
	virtual std::string message(int ev) const
	{
		std::string msg;
		switch (ev)
		{
		case 0:
			msg = "ok";
			break;
		default:
			msg = "some error";
			break;
		}
		return msg;
	}
};



int main()
{
	std::cout << system_category().name() << std::endl;

	error_code ec;
	assert(ec.value() == errc::success);
	assert(!ec);

	assert(ec.category() == system_category());
	ec.assign(3L, system_category());
	error_condition econd = ec.default_error_condition();

	assert(econd == system_category().default_error_condition(3L));

	std::cout << ec.message() << std::endl;
	std::cout << econd.message() << std::endl;
	std::cout << econd.value() << std::endl;
}