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

int main()
{
	any a(10); 
	int n = any_cast<int>(a);
	assert(n == 10);

	any_cast<int&>(a) = 20;
	assert(any_cast<int>(a) == 20);

	try
	{
		any b;
		//any_cast<int>(b);
	}
	catch (boost::exception&)
	{
		std::cout << current_exception_diagnostic_information();
	}
	any a1, a2(2.0);
	assert(any_cast<int*>(&a1) == 0);
	//std::cout << "111" << std::endl;
	assert(any_cast<std::string*>(&a2) == 0);

	any b(100);
	b = std::string("char*");
	b = std::vector<std::vector<int> >();
	b = "c str";

	b = std::string("avatar");
	std::cout << any_cast<std::string>(b);
	//any_cast<int>(b);

	std::string *ps = new std::string("abc");
	a = ps;
	if (!a.empty() && any_cast<std::string*>(a))
	{
		std::cout << *any_cast<std::string*>(a) << std::endl;
	}

	std::shared_ptr<std::string> bs = std::shared_ptr<std::string>(new std::string("edf"));
	a = bs;
	std::cout << *any_cast<std::shared_ptr<std::string>>(a) << std::endl;
}