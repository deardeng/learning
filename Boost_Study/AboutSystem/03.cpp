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
	my_category my_cat;
	error_code ec(10, my_cat);
	std::cout << ec.value() << ec.message() << std::endl;
	ec = error_code(10, system_category());
	std::cout << ec.value() << ec.message() << std::endl;

	//ERROR
	//error_code的构造函数接受的是error_category的引用，不会拷贝副本。
	// 代码虽然可以正确编译，但运行时因为临时对象在语句结束后析构，在调用message()成员函数时会发生未定义行为。
	{
		ec = error_code(10, my_category());
		std::cout << ec.value() << ec.message() << std::endl;
	}
}