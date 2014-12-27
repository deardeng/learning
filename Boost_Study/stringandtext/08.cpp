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
using namespace boost;
using namespace std;

int main()
{
	format fmt("|%s|\n");

	string str = " samus aran   ";
	cout << fmt % trim_copy(str);
	cout << fmt % trim_left_copy(str);

	trim_right(str);
	cout << fmt % str;

	string str2 = "2015 Happy     new Year!!!";
	cout << fmt % trim_left_copy_if(str2, is_digit());
	cout << fmt % trim_right_copy_if(str2, is_punct());
	cout << fmt % trim_copy_if(str2, is_punct()||is_digit()||is_space());

}