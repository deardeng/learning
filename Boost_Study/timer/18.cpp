#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;


int main()
{
	ptime p5(date(2010, 3, 5), hours(1));
	ptime p1 = time_from_string("2010-3-5 01:00:00");
	ptime p2 = from_iso_string("20100305T010000");

	ptime p3 = second_clock::local_time();
	ptime p4 = microsec_clock::universal_time();

	cout << p3 << endl << p4;

	ptime p(date(2010, 3, 20), hours(12) + minutes(30));
	date d = p.date();
	time_duration td = p.time_of_day();
	assert(d.month() == 3 && d.day() == 20);
	assert(td.total_seconds() == 12*3600 + 30*60);

	ptime p6(date(2010, 3, 20), hours(12)+minutes(30));
	ptime p7 = p6 + hours(3);
	assert(p6 < p7);
	assert(p7 - p6 == hours(3));
	p7 += months(1);
	assert(p7.date().month() == 4);

	cout << endl;

	ptime p8(date(2014, 12, 1), hours(17));
	cout << to_simple_string(p8) << endl;
	cout << to_iso_string(p8) << endl;
	cout << to_iso_extended_string(p8) << endl;
}