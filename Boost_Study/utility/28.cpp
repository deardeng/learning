#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <sstream>

#include <boost/config/suffix.hpp>

using namespace std;

struct static_int
{
	static const int v1 = 10;
	enum {v2 = 20};
	int a[v2];
	BOOST_STATIC_CONSTANT(int, v3 = 10);

};

int main()
{
	cout << BOOST_STRINGIZE(__LINE__) << endl;
	cout << std::boolalpha << (string("22") == BOOST_STRINGIZE(__LINE__)) << endl;
	int x = 255;
	cout << BOOST_STRINGIZE(x) << endl;
	static_int a;
	cout << a.v3 << endl;

}