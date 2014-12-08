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
	ptimer t;
	for(int i=0; i<1000000000;i++)
	{
		//
	}
}