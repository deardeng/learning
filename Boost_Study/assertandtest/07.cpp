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

struct my_error
{
	int err_code;
	my_error(int ec):err_code(ec){}
};

void translate_my_err(const my_error& e)
{
	cout << "my err = " << e.err_code << endl;
}

int f()
{
	std::cout << "f execute." << std::endl;
	throw my_error(100);
	return 5;
}

int main()
{
	execution_monitor em;
	em.register_exception_translator<my_error>(&translate_my_err);
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