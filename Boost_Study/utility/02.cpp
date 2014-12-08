#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/make_shared.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/typeof/typeof.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
namespace ex
{
	struct demo_class
	{
		int a, b;
	};
}
BOOST_TYPEOF_REGISTER_TYPE(ex::demo_class)

#define auto_t BOOST_AUTO

using namespace boost;
int main()
{
	BOOST_AUTO(x, std::make_pair("test", ex::demo_class()));
	std::cout << typeid(x).name() << std::endl;
	x.second.a = 10;
	x.second.b = 20;
	std::cout << x.second.a << ' ' << x.second.b << std::endl;

	//shared_ptr<std::string> sp = make_shared<std::string>("make_shared");
	auto_t(p, make_shared<int>(10));
	assert(*p = 10);

}