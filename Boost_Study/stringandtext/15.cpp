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
	char *str = "Link ;; <master-sword> zelda";

	char_separator<char> sep;
	tokenizer<char_separator<char>, char*> tok(str, str+strlen(str), sep);
	print(tok);

	tok.assign(str, str+strlen(str),
		char_separator<char>(" ;-", "<>"));
	print(tok);

	tok.assign(str, str+strlen(str),
		char_separator<char>(" ;-<>", "", keep_empty_tokens));
	print(tok);
}