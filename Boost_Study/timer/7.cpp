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
	date d(2010, 2, 1);
	tm t = to_tm(d);
	assert(t.tm_hour == 0 && t.tm_min == 0);
	assert(t.tm_year == 110 && t.tm_mday == 1);

	date d2 = date_from_tm(t);
	assert(d == d2);

	days dd1(10), dd2(-100), dd3(255);

	assert(dd1 > dd2 && dd1 < dd3);
	assert(dd1 + dd2 == days(-90));
	assert((dd1 + dd3).days() == 265);
	assert(dd3 / 5 == days(51));

	weeks w(3);
	assert(w.days() == 21);

	months m(5);
	years y(2);

	months m2 = y+m;
	assert(m2.number_of_months() == 29);
	assert((y*2).number_of_years() == 4);
}