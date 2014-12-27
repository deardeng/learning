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
#include <boost/tokenizer.hpp>
using namespace boost;
using namespace std;

int main()
{
	string str("Link raise the master-sword.");
	tokenizer<> tok(str);

	for(BOOST_AUTO(pos, tok.begin()); pos!=tok.end(); ++pos)
	{
		cout << '[' << *pos << ']';
	}

}