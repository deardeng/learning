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
	date d(1982, 05, 19);

	date d18years = d + years(26);
	cout << d18years << " is " << d18years.day_of_week() << endl;

	int count = 0;
	for(day_iterator d_iter(date(d18years.year(), 5, 1)); d_iter != d18years.end_of_month(); ++d_iter)
	{
		if(d_iter->day_of_week() == Sunday)
		{
			++count;
		}
	}
	cout << "total " << count << " Sundays." << endl;

	count = 0;
	for(month_iterator m_iter(date(d18years.year(), 1, 1));
		m_iter < date(d18years.year() + 1, 1, 1); ++m_iter)
	{
		count += m_iter->end_of_month().day();
	}
	cout << "total " << count << " days of year." << endl;
	typedef gregorian_calendar gre_cal;
	cout << d18years << endl;
	cout << (gre_cal::is_leap_year(d18years.year())?366:365);
}