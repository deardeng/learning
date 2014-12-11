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

#define DEFINE_ERROR_INFO(type, name) \
	typedef boost::error_info<struct tag_##name, type> name

int main()
{
	DEFINE_ERROR_INFO(double, err_do);
	try
	{
		
		throw my_exception() << err_do(7.8);
		throw my_exception() << errinfo_api_function("call api")
			<< errinfo_errno(101) << errinfo_file_name("19.cpp");
	}
	catch(boost::exception& e)
	{
		cout << *get_error_info<err_do>(e) << endl;
		return 0;
		cout << *get_error_info<errinfo_api_function>(e) << endl;
		cout << *get_error_info<errinfo_errno>(e) << endl;
		cout << *get_error_info<errinfo_file_name>(e) << endl;
	}

}