#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


#include <boost/date_time/gregorian/gregorian.hpp>
#include "boost/date_time/gregorian/greg_date.hpp"
using namespace std;
using namespace boost::gregorian;

int main()
{
	date_period dp1(date(2014, 11, 28), days(20));
	date_period dp2(date(2014, 11, 28), date(2010, 1, 1));
	date_period dp3(date(2014, 11, 28), days(-20));
	cout << dp1 << ' ' << dp2 << ' ' << dp3 << endl;
	cout << dp2.length() << endl;
	cout << dp2.is_null() << endl;
	date_period dp(date(2010, 1, 1), days(20));
	assert(!dp.is_null());
	assert(dp.begin().day() == 1);
	assert(dp.last().day() == 20);
	assert(dp.end().day() == 21);
	assert(dp.length().days() == 20);
}