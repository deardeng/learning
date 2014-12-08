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
	date_facet* dfacet = new date_facet("%Y 年 %m 月 %d 日");
	cout.imbue(locale(cout.getloc(), dfacet));
	cout << d << endl;

	time_facet *tfacet = new time_facet("%Y 年 %m 月 %d 日 %H 点 %M 分 %S%F秒");
	cout.imbue(locale(cout.getloc(), tfacet));
	cout << ptime(d, hours(21) + minutes(50) + millisec(100)) << endl;
}