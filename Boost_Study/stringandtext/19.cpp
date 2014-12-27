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
	char* str = "there is a POWER-suit item";
	cregex reg = cregex::compile("(power)-(.{4})", icase);

	assert(regex_search(str, reg));

	cmatch what;
	regex_search(str, what, reg);
	assert(what.size() == 3);
	cout << what[0] << endl;
	cout << what[1] << endl;
	cout << what[2] << endl;
	assert(!regex_search("error message", reg));


	string str1("readme.TXT");
	sregex start_reg = sregex::compile("^re");
	sregex end_reg = sregex::compile("txt$", icase);

	assert(regex_search(str1, start_reg));
	assert(regex_search(str1, end_reg));
	assert(regex_search(str1, sregex::compile((const char*)"me")));
}