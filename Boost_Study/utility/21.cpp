#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/exception/all.hpp>
using namespace boost;
using namespace std;

struct my_err{};

int main()
{
	using namespace boost;
	try
	{
		throw enable_error_info(my_err()) << errinfo_errno(101)
			<< errinfo_api_function("fopen");
	}
	catch(boost::exception& e)
	{
		cout << diagnostic_information(e) << endl;
	}

	try
	{
		BOOST_THROW_EXCEPTION(std::logic_error("logic"));
	}
	catch(boost::exception& e)
	{
		cout << diagnostic_information(e) << endl;
	}

}