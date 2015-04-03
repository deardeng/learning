#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <boost/test/impl/execution_monitor.ipp>
#include <boost/test/impl/debug.ipp>


#define BOOST_TEST_INCLUDED
#include <boost/test/execution_monitor.hpp>
using namespace boost;

int f()
{
	std::cout << "f execute." << std::endl;
	throw "a error accoured";
	return 5;
}

int main()
{
	execution_monitor em;
	try
	{
		em.execute(unit_test::callback0<int>(f));
	}
	catch(execution_exception& e)
	{
		std::cout << "execution_exception" << std::endl;
		std::cout << e.what().begin() << std::endl;
	}
}