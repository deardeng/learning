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
using namespace boost;
using namespace std;

int main()
{
	string str = "Samus, Link.Zelda::Mario-Luigi+zelda";
	deque<string> d;
	ifind_all(d, str, "zELDA");
	assert(d.size() == 2);
	for(BOOST_AUTO(pos, d.begin()); pos!=d.end(); ++pos)
	{
		cout << "[" << *pos << "]";
	}
	cout << endl;

	list<iterator_range<string::iterator> > l;
	split(l, str, is_any_of(",.:-+ "));
	for(BOOST_AUTO(pos, l.begin()); pos!=l.end(); ++pos)
	{
		cout << "[" << *pos << "]";
	}
	cout << endl;

	l.clear();
	split(l, str,is_any_of(" .:-"),token_compress_on);
	for(BOOST_AUTO(pos, l.begin()); pos!=l.end(); ++pos)
	{
		cout << '[' << *pos << ']';
	}
	cout << endl;
}