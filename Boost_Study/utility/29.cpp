#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <boost/utility.hpp>
#include <boost/config/suffix.hpp>
#include <boost/config/warning_disable.hpp>
#include <bitset>
using namespace std;


int main()
{
	cout << hex << showbase;
	cout << BOOST_BINARY(0110) << endl;
	cout << BOOST_BINARY(0110 1101) << endl;
	cout << BOOST_BINARY(10110110 01) << endl;
	cout << bitset<5>(BOOST_BINARY(0110)) << endl;
	cout << BOOST_BINARY_UL(101 1001) << endl;
	long long x = BOOST_BINARY_LL(1101);
	cout << x << endl;
}