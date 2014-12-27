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
	string str("Samus||samus||mario||||Link");

	typedef find_iterator<string::iterator> string_find_iterator;

	string_find_iterator pos, a;

	for(pos = make_find_iterator(str, first_finder("samus", is_iequal()));
		pos!=a; ++pos)
	{
		cout << '[' << *pos << ']';
	}
	cout << endl;

	typedef split_iterator<string::iterator> string_split_iterator;

	string_split_iterator p,endp;
	for(p=make_split_iterator(str, first_finder("||", is_iequal()));
		p!=endp; ++p)
	{
		cout << '[' << *p << ']';
	}
	cout << endl;

}