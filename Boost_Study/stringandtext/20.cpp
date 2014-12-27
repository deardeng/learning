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
	string str("readme.txt");
	
	sregex reg1 = sregex::compile("(.*)(me)");
	sregex reg2 = sregex::compile("(t)(.)(t)");

	cout << regex_replace(str, reg1, "manual") << endl;
	cout << regex_replace(str, reg1, "$1you") << endl;
	cout << regex_replace(str, reg1, "$&$&") << endl;
	cout << regex_replace(str, reg2, "$1N$3") << endl;

	str = regex_replace(str, reg2, "$1$3");
	cout << str << endl;

	string str1("2015 Happy new Year!!!");
	sregex reg3 = sregex::compile("^(\\d| )*");
	sregex reg4 = sregex::compile("!*$");
	
	cout << regex_replace(str1, reg3, "") << endl;
	cout << regex_replace(str1, reg4, "") << endl;
	str1 = regex_replace(str1, reg3, "Y2000 ");
	cout << str1 << endl;
}