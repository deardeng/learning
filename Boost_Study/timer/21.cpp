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

class work_time
{
public:
	typedef map<time_period, string>map_t;
private:
	map_t map_ts;
	void init()
	{
		ptime p(day_clock::local_day());
		map_ts[time_period(p, hours(9))] = "It's too early, just relax.\n";
		p += hours(9);
		map_ts[time_period(p, hours(3)+minutes(30))] = "It's AM, please work hard.\n";
		p += hours(3) + minutes(30);
		map_ts[time_period(p, hours(1))] = "It's lunch time, are you hungry?\n";
		p += hours(1);
		map_ts[time_period(p, hours(4) + minutes(30))] = "It's PM, ready to go home.\n";
		p += hours(4) + minutes(30);
		map_ts[time_period(p, hours(6))] = "Are you still working? you do need a rest.\n";
	}
public:
	work_time()
	{
		init();
	}
	void greeting(const ptime& t)
	{
		map_t::iterator pos;
		for(pos = map_ts.begin(); pos != map_ts.end(); ++pos)
		{
			if(pos->first.contains(t))
			{
				cout << pos->second << endl;
				break;
			}
		}
	}
};

int main()
{
	work_time wt;
	wt.greeting(second_clock::local_time() + hours(8));
}