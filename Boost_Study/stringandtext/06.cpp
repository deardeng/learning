#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <boost/algorithm//string.hpp>
using namespace boost;

using namespace std;

int main()
{
	string str("readme.txt");
	if(ends_with(str, "txt"))
	{
		cout << to_upper_copy(str) + " UPPER" << endl;
		assert(ends_with(str, "txt"));
	}

	replace_first(str, "readme", "followme");
	cout << str << endl;

	vector<char> v(str.begin(), str.end());
	vector<char> v2 = to_upper_copy(erase_first_copy(v, "txt"));
	for(int i=0; i<v2.size(); ++i)
	{
		cout << v2[i];
	}
}