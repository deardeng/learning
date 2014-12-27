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
	char* str = "*Link*||+Mario+||Zelda!!!||Metroid_";
	cregex reg = cregex::compile("\\w+", icase);
	cregex_token_iterator pos(str, str+strlen(str), reg);
	while(pos != cregex_token_iterator())
	{
		cout << "[" << *pos << "]";
		++pos;
	}
	cout << endl;

	cregex split_reg = cregex::compile("\\|\\|");
	pos = cregex_token_iterator(str, str+strlen(str), split_reg, -1);

	while(pos != cregex_token_iterator())
	{
		cout << "[" << *pos << "]";
		++pos;
	}
	cout << endl;


	cregex_compiler rc;
	rc["reg1"] = rc.compile("a|b|c");
	rc["reg2"] = rc.compile("\\d*");
	assert(regex_match("b", rc["reg1"]));
	assert(regex_match("123", rc["reg2"]));
}