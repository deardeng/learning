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

struct my_exception:
	virtual std::exception,
	virtual boost::exception
{};

typedef boost::error_info<struct tag_err_no, int> err_no;
typedef boost::error_info<struct tag_err_str, string> err_str;

int main()
{
	try
	{
		using namespace boost;
		try
		{
			throw my_exception() << err_no(10);
		}
		catch(my_exception& e)
		{
			cout << *get_error_info<err_no>(e) << endl;
			cout << e.what() << endl;
			e << err_str("other info");
			throw;
		}
	}
	catch(my_exception& e)
	{
		cout << *get_error_info<err_str>(e) << endl;
	}
}