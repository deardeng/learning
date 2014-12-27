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
using namespace boost;
using namespace boost::xpressive;
using namespace std;


int main()
{
	cregex reg10 = cregex::compile("a.c");
	assert(regex_match("abc", reg10));
	assert(regex_match("a+c", reg10));
	
	assert(!regex_match("ac", reg10));
	assert(!regex_match("abd", reg10));


	cregex reg = cregex::compile("\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))", icase);

	assert(regex_match("999555197001019999", reg));
	assert(regex_match("99955519700101999X", reg));
	assert(regex_match("99955520100101999x", reg));

	assert(!regex_match("99955520100101999z", reg));
	assert(!regex_match("999555201099019998", reg));

	cmatch what;
	assert(regex_match("999555197001019999", what, reg));
	for(BOOST_AUTO(pos, what.begin()); pos!=what.end(); ++pos)
	{
		cout << "[" << *pos << "]";
	}
	cout << endl;

	cout << "date:" << what[1] << what[3] << what[5] << endl;

	string str1("readme.txt");

	sregex start_reg = sregex::compile("^re.*");
	sregex end_reg = sregex::compile(".*txt$");

	assert(regex_match(str1, start_reg));
	assert(regex_match(str1, end_reg));
}