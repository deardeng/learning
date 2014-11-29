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
	date d(2006, 11, 26);
	day_iterator d_iter(d);

	assert(d_iter == d);
	++d_iter;
	assert(d_iter == date(2006, 11, 27));

	year_iterator y_iter(*d_iter, 3);
	assert(y_iter == d + days(1));
	cout << *d_iter << endl;
	cout << *y_iter << endl;
	++y_iter;
	assert(y_iter->year() == 2009);

	typedef gregorian_calendar gre_cal;
	cout << "Y2010 is " << (gre_cal::is_leap_year(2010)?"":"not") << " a leap year." << endl;
	assert(gre_cal::end_of_month_day(2010, 2) == 28);
}