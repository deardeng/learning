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
	date d(2010, 3, 6);
	date_facet* dfacet = new date_facet("%Y �� %m �� %d ��");
	cout.imbue(locale(cout.getloc(), dfacet));
	cout << d << endl;

	time_facet *tfacet = new time_facet("%Y �� %m �� %d �� %H �� %M �� %S%F��");
	cout.imbue(locale(cout.getloc(), tfacet));
	cout << ptime(d, hours(21) + minutes(50) + millisec(100)) << endl;
}