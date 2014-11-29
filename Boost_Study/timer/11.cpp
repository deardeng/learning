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
	date_period dp(date(2010, 1, 1), days(20));
	assert(dp.is_after(date(2009, 12, 1)));
	assert(dp.is_before(date(2010, 2, 1)));
	assert(dp.contains(date(2010,1,5)));

	date_period dp2(date(2010, 1, 5), days(10));
	assert(dp.contains(dp2));
	assert(dp.intersects(dp2));
	assert(dp.intersection(dp2) == dp2);
	cout << dp.intersection(dp2) << endl;

	date_period dp3(date(2010, 1, 21), days(5));
	assert(!dp3.intersects(dp2));
	assert(dp3.intersection(dp2).is_null());
	cout << dp3.intersection(dp2) << endl;

	assert(dp.is_adjacent(dp3));
	assert(!dp.intersects(dp3));

	date_period dp5(date(2010, 1, 1), days(20));
	date_period dp6(date(2010, 1, 5), days(10));
	date_period dp7(date(2010, 2, 1), days(5));
	date_period dp8(date(2010, 1, 15), days(10));

	assert(dp5.contains(dp6) && dp5.merge(dp6) == dp5);
	assert(!dp5.intersects(dp7) && dp5.merge(dp7).is_null());
	cout << dp5 << ' ' << dp8 << endl;
	assert(dp5.intersects(dp6) && dp5.merge(dp8).end() == dp8.end());
	cout << dp5.merge(dp8) << endl;
	assert(dp5.span(dp7).end() == dp7.end());
	cout << dp5.span(dp7) << endl;

}