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

typedef tuple<errinfo_api_function, errinfo_errno > err_group;

int main()
{
	try
	{
		throw enable_error_info(std::out_of_range("out")) << err_group("syslogd", 874);
	}
	catch(boost::exception& )
	{
		cout << current_exception_cast<std::exception>()->what() << endl;
		//cout << current_exception_diagnostic_information() << endl;
	}
}