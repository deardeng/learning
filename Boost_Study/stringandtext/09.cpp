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
using namespace boost;
using namespace std;

int main()
{
	format fmt("|%s|. pos = %d\n");
	string str = "Long long ago, there was a king.";
	iterator_range<string::iterator> rge;
	rge = find_first(str, "long");
	cout << fmt % rge % (rge.begin() - str.begin());

	rge = ifind_first(str, "long");
	cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_nth(str, "ng", 1);
	cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_head(str, 4);
	cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_tail(str, 5);
	cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_first(str, "samus");
	assert(rge.empty() && !rge);

}