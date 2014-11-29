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
	date d(2008, 11, 20);
	date d_start(d.year(), d.month(), 1);
	date d_end = d.end_of_month();

	for(day_iterator d_iter(d_start); d_iter != d_end; ++d_iter)
	{
		cout << *d_iter << " " << d_iter->day_of_week() << endl;
	}
}