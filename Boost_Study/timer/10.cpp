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
	date_period dp(date(2014, 11, 28), days(20));
	
	dp.shift(days(3));
	assert(dp.begin().day() == 1);
	assert(dp.length().days() == 20);

	dp.expand(days(3));
	assert(dp.begin().day() == 28);
	assert(dp.length().days() == 26);
}