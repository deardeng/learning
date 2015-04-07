#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/any.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/make_shared.hpp>
using namespace boost;

template<typename T>
bool can_cast(any &a)
{
	return typeid(T) == a.type();
}

template<typename T>
T& get(any &a)
{
	BOOST_ASSERT(can_cast<T>(a));
	return *any_cast<T>(&a);
}

template<typename T>
T* get_pointer(any &a)
{
	BOOST_ASSERT(can_cast<T>(a));
	return any_cast<T>(&a);
}

template<typename T>
any make_ptr_any(T *p = 0)
{
	return any(shared_ptr<T>(p));
}

template<typename T>
shared_ptr<T>& get_shared(any &a)
{
	BOOST_ASSERT(can_cast<shared_ptr<T>>(a));
	return *any_cast<shared_ptr<T>>(&a);
}

template<typename T>
struct any_print
{
	void operator()(any &a)
	{
		try
		{
			std::cout << *any_cast<T>(&a) << std::endl;
		}
		catch (bad_any_cast &)
		{
			std::cout << "print error" << std::endl;
		}
	}
};

template<typename T>
struct any_print < shared_ptr<T> >
{
	void operator()(any &a)
	{
		try
		{
			std::cout << **any_cast<shared_ptr<T>>(&a) << std::endl;
		}
		catch (bad_any_cast &)
		{
			std::cout << "print error" << std::endl;
		}
	}
};

template<typename T>
void inline any_print_func(any &a)
{
	any_print<T>()(a);
}

int main()
{
	any a;
	char* str = "string";
	a = str;
	any_print<char*>()(a);
	a = 10;
	any_print<int>()(a);
	shared_ptr<std::string> ps = make_shared<std::string>("metroid");
	a = ps;
	any_print<shared_ptr<std::string> >()(a);
	any_print_func<shared_ptr<std::string> >(a);


	std::vector<any> v;
	v.push_back(10);
	v.push_back(1.414);
	v.push_back(shared_ptr<int>(new int(100)));

	using namespace boost::assign;
	std::vector<any> v2 = list_of<any>(10) (0.618) (std::string("char"));
	std::cout << v2.size() << std::endl;
}