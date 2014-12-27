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
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost;
using namespace boost::xpressive;
using namespace std;


int main()
{
	string str("Power-bomb, power-suit, pOWER-beam all items\n");
	sregex reg = sregex::compile("power-(\\w{4})", icase);
	sregex_iterator pos(str.begin(), str.end(), reg);
	sregex_iterator end;
	while(pos != end)
	{
		cout << '[' << (*pos)[0] << ']';
		++pos;
	}
	cout << endl;
}