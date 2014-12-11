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
		//throw enable_error_info(std::runtime_error("runtime")) << errinfo_at_line(__LINE__);
		throw_exception(std::runtime_error("runtime"));
		throw enable_error_info(my_err()) << errinfo_errno(10);
	}
	catch(std::exception& e)
	{
		//cout << *get_error_info<errinfo_at_line>(e) << endl;
		cout << e.what() << endl;
	}
}