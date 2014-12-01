#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost::posix_time;


int main()
{
	time_duration td(1, 10, 30, 1000);
	time_duration td1(1,60,60,1000*1000*6 + 1000);
	cout << td << ' ' << td1 << endl;

	hours h(1);
	minutes m(10);
	seconds s(30);
	millisec ms(1);
	time_duration td2 = h + m + s + ms;
	time_duration td3 = hours(2) + seconds(10);
	cout << td2 << ' ' << td3 << endl;


	time_duration td4 = duration_from_string("1:10:30:001");
	assert(td4.hours() == 1 && td.seconds() == 30);

	hours b(-10);
	assert(b.is_negative());
	time_duration h2 = b.invert_sign();
	assert(!h2.is_negative() && h2.hours() == 10);
}