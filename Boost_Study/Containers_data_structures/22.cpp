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

int main()
{
	any a;
	int x = 1;
	a = x;
	assert(can_cast<int>(a));
	get<int>(a) = 10;
	*get_pointer<int>(a) = 20;

	any b = make_ptr_any<std::string>(new std::string("long"));
	b = make_ptr_any <std::vector<int> >(new std::vector<int>);
	any c = make_ptr_any<std::string>(new std::string("avatar"));
	std::cout << *any_cast<shared_ptr<std::string>>(c) << std::endl;
	std::cout << *get<shared_ptr<std::string> >(c) << std::endl;

	std::cout << *get_shared<std::string>(c) << std::endl;
}