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

template<typename T>
void print(T &tok)
{
	for(BOOST_AUTO(pos, tok.begin()); pos!=tok.end(); ++pos)
	{
		cout << '[' << *pos << ']';
	}
	cout << endl;
}

int main()
{
	string str10 = "id,100,name,\"mario\"";

	escaped_list_separator<char> sep10;
	tokenizer<escaped_list_separator<char> > tok10(str10, sep10);
	print(tok10);

	string str = "2233344445";
	int offsets[] = {2, 3, 4};
	offset_separator sep(offsets, offsets+3, true, false);
	tokenizer<offset_separator> tok(str, sep);
	print(tok);

	tok.assign(str, offset_separator(offsets, offsets+3, false));
	print(tok);
	

	str += "56667";
	tok.assign(str, offset_separator(offsets, offsets+3, true, false));
	print(tok);
}