#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;


int main()
{
	
	ptime p(date(2010, 1, 1), hours(12));
	time_period tp1(p, hours(8));
	time_period tp2(p+hours(8), hours(1));
	//cout << tp1 << ' ' << tp2 << endl;
	assert(tp1.end() == tp2.begin() && tp1.is_adjacent(tp2));
	assert(!tp1.intersects(tp2));
	
	tp1.shift(hours(1));
	//cout << tp1 << endl;
	assert(tp1.is_after(p));
	assert(tp1.intersects(tp2));

	tp2.expand(hours(10));
	assert(tp2.contains(p) && tp2.contains(tp1));


	ptime p3(date(2010, 2, 27), hours(10));
	cout << p3 + hours(1) << endl;
	for(time_iterator t_iter(p3, minutes(1));
		t_iter < p3 + hours(1); ++t_iter)
	{
		cout << *t_iter << endl;
	}
}