#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
#define BOOST_DATE_TIME_SOURCE
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost::posix_time;


int main()
{
	time_duration td(1, 10, 30, 1000);
	cout << td;
	assert(td.total_milliseconds() == td.total_seconds()*1000);
	assert(td.fractional_seconds() == 1000);
	assert(time_duration::unit()*1000*1000*1000 == seconds(1));
	
	assert(td.num_fractional_digits() == 9);
}