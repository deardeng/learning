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
	date d(2010, 4, 1);
	assert(d.year() == 2010);
	assert(d.month() == 4);
	assert(d.day() == 1);

	date::ymd_type ymd = d.year_month_day();
	assert(ymd.year == 2010);
	assert(ymd.month == 4);
	assert(ymd.day == 1);

	assert(d.day_of_week() == 4);
	assert(d.day_of_year() == 91);
	assert(d.end_of_month() == date(2010, 4, 30));

	date d2(day_clock::local_day());
	cout << d2 << endl;
	cout << d2.day_of_week() << endl;
	cout << d2.day_of_year() << endl;
	cout << d2.end_of_month() << endl;

	date d3(2008, 11, 20);
	cout << to_simple_string(d3) << endl;
	cout << to_iso_string(d3) << endl;
	cout << to_iso_extended_string(d3) << endl;
	cout << d3 << endl;

	cout << "---------------------------------" << endl;
	date d4;
	cin >> d4;
	cout << d4;
}