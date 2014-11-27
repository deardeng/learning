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
	date d1;
	date d2(2010, 1, 1);
	date d3(2000, Jan, 1);
	date d4(d2);

	assert(d1 == date(not_a_date_time));
	assert(d2 == d4);
	assert(d3 < d4);

	date d5 = from_string("1999-12-31");
	date d6 (from_string("2005/1/1"));
	date d7 = from_undelimited_string("20011118");

	cout << d5 << endl;
	cout << d6 << endl;
	cout << d7 << endl;

	cout << day_clock::local_day() << endl;
	cout << day_clock::universal_day() << endl;

	date d8(neg_infin);
	date d9(pos_infin);
	date d10(not_a_date_time);
	date d11(max_date_time);
	date d12(min_date_time);

	cout << d8 << endl;
	cout << d9 << endl;
	cout << d10 << endl;
	cout << d11 << endl;
	cout << d12 << endl;

	try
	{
		date d14(2010, 2, 29);
		date d13(1399, 12, 1);
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
}