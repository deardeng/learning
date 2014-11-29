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
	date d1(2000, 1, 1), d2(2014, 11, 28);
	cout << d2 -d1 << endl;
	assert(d1 + (d2-d1) == d2);

	d1 += days(10);
	assert(d1.day() == 11);;
	d1 += months(2);
	assert(d1.month() == 3 && d1.day() == 11);
	d1 -= weeks(1);
	assert(d1.day() == 4);

	d2 -= years(7);
	assert(d2.year() == d1.year() + 7);

	date d3(2010, 1, 1);
	date d4 = d1 + days(pos_infin);
	assert(d4.is_pos_infinity());

	d4 = d3 + days(not_a_date_time);
	assert(d4.is_not_a_date());
	d4 = date(neg_infin);
	days dd = d3 - d4;

	assert(dd.is_special() && !dd.is_negative());

	date d(2010, 3, 30);
	d -= months(1);
	d -= months(1);
	d += months(2);

	assert(d.day() == 31);

}