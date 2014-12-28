#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <cassert>

#include <boost/format.hpp>
namespace boost
{
	void assertion_failed(char const* expr, char const* function, char const* file, long line)
	{
		boost::format fmt("Assertion failed!\n Expression: %s\nFunction: %s\nFile: %s\nLine: %ld\n\n");
		fmt % expr % function% file %line;
		std::cout << fmt;
	}
}
#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>
using namespace std;

double func(int x)
{
	BOOST_ASSERT(x != 0 && "divided by zero");
	//cout << "after BOOST_ASSERT" << endl;
	//assert(x != 0 && "divided by zero");
	//cout << "after" << endl;
	return 1.0 / x;
}

int main()
{
	BOOST_ASSERT(16 == 0x10);
	BOOST_ASSERT(string().size() == 0);
	func(0);
}