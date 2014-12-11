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

void thread_work()
{
	throw_exception(std::exception("test"));
}

int main()
{
	using namespace boost;
	try
	{
		thread_work();
	}
	catch(...)
	{
		boost::exception_ptr e = boost::current_exception();
		cout << current_exception_diagnostic_information();
	}
}