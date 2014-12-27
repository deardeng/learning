#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <boost/algorithm/string.hpp>
using namespace boost;

using namespace std;

int main()
{
	//string str("I Don't Know.\n");
	//cout << to_upper_copy(str);
	//cout << str;
	//to_lower(str);
	//cout << str;
	string str("Power Bomb");
	assert(iends_with(str, "bomb"));
	assert(!ends_with(str, "bomb"));
	assert(starts_with(str, "Pow"));
	assert(contains(str, "er"));
	string str2 = to_lower_copy(str);
	assert(iequals(str, str2));

	string str3("power suit");
	assert(ilexicographical_compare(str, str3));

	assert(all(str2.substr(0, 5), is_lower()));

	string str4("Samus"), str5("samus");
	assert(!is_equal()(str4, str5));
	assert(is_less()(str4, str5));
}