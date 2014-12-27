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

struct formater
{
	string operator()(cmatch const &m)const
	{
		return boost::to_upper_copy(m[0].str());
	}
};

int main()
{
	char* str = "*Link*||+Mario+||Zelda!!!||Metroid";
	cregex reg = cregex::compile("\\w+", icase);
	cout << regex_replace(str, reg, formater()) << endl;
}