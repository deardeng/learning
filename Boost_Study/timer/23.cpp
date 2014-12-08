#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace boost::local_time;

template<typename Clock = microsec_clock>
class basic_ptimer
{
public:
	basic_ptimer()
	{
		restart();
	}
	void restart()
	{
		_start_time = Clock::local_time();
	}
	void elapsed() const
	{
		cout << Clock::local_time() - _start_time;
	}
	~basic_ptimer()
	{
		elapsed();
	}
private:
	ptime _start_time;
};
typedef basic_ptimer<microsec_clock> ptimer;
typedef basic_ptimer<second_clock> sptimer;


int main()
{
		tz_database tz_db;
		{
			ptimer t;
			tz_db.load_from_file("./date_time_zonespec.csv");
		}
		cout << endl;

		time_zone_ptr shz = tz_db.time_zone_from_region("Asia/Shanghai");

		time_zone_ptr nyz = tz_db.time_zone_from_region("America/New_York");

		cout << shz->has_dst() << endl;
		cout << shz->std_zone_name() << endl;

		local_date_time dt_bj(date(2008, 1, 7), hours(12), shz, false);
		cout << dt_bj << endl;

		time_duration flight_time = hours(15);
		dt_bj += flight_time;
		cout << dt_bj << endl;
		local_date_time dt_ny = dt_bj.local_time_in(nyz);
		cout << dt_ny;
}