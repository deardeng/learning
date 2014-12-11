#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>

#include <boost/lexical_cast.hpp>
using namespace boost;
using namespace std;

int main()
{
	using namespace boost;
	int x = lexical_cast<int>("100");
	long y = lexical_cast<long>("2000");
	float pai = lexical_cast<float>("3.14159e5");
	double e = lexical_cast<double>("2.71828");

	cout << x << ' ' << y << ' ' << pai << ' ' << e << ' ' << endl;

	string str = lexical_cast<string>(456);
	cout << str << endl;
	cout << lexical_cast<string>(0.618) << endl;
	cout << lexical_cast<string>(0x10) << endl;

	cout << lexical_cast<bool>("1") << endl;
}