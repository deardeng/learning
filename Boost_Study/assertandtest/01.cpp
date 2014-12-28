#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define BOOST_DISABLE_ASSERTS
#include <cassert>
#include <boost/assert.hpp>
using namespace std;

double func(int x)
{
	BOOST_ASSERT(x != 0 && "divided by zero");
	cout << "after BOOST_ASSERT" << endl;
	assert(x != 0 && "divided by zero");
	cout << "after" << endl;
	return 1.0 / x;
}

int main()
{
	BOOST_ASSERT(16 == 0x10);
	BOOST_ASSERT(string().size() == 0);
	func(0);
}