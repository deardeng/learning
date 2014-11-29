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

class credit_card{
public:
	string bank_name;
	int bill_day_no;
	credit_card(const char* bname, int no):bank_name(bname), bill_day_no(no){}

	int calc_free_days(date consume_day = day_clock::local_day()) const
	{
		date bill_day(consume_day.year(), consume_day.month(), bill_day_no);
		if(consume_day > bill_day)
		{
			bill_day += months(1);
		}
		return (bill_day - consume_day).days() + 20;
	}

	friend bool operator<(const credit_card& l, const credit_card& r)
	{
		return l.calc_free_days() < r.calc_free_days();
	}
};
int main()
{
	credit_card a("A bank", 25);
	credit_card b("B bank", 12);

	credit_card tmp = std::max(a, b);
	cout << "You should use " << tmp.bank_name << ", free days = " << tmp.calc_free_days() << endl;
	cout << a.calc_free_days(date(2010, 5, 26));
}