#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <boost/current_function.hpp>

using namespace std;

double func()
{
	cout << BOOST_CURRENT_FUNCTION << endl;
	return 0.0;
}

int main()
{
	cout << __FUNCTION__ << endl;
	cout << BOOST_CURRENT_FUNCTION << endl;
	func();
}