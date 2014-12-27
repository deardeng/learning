#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace std;

int main()
{
	using namespace boost::assign;
	vector<string> v = list_of("Samus")("Link")("Zelda")("Mario");
	cout << join(v, "+") << endl;

	struct is_contains_a
	{
		bool operator()(const string &x)
		{
			return contains(x, "a");
		}
	};
	cout << join_if(v, "**", is_contains_a());
}