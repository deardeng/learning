#include <boost/timer.hpp>
#include <boost/progress.hpp>

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


using namespace boost;

int main()
{
	timer t;
	cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	cout << "min timespan:" << t.elapsed_min() << "s" << endl;
	cout << "now time elapsed:" << t.elapsed() << "s" << endl;
	{
		boost::progress_timer t;
		for(int i=0; i<10; ++i)
		{
			cout << '1';
		}
		cout << endl;
	}

	{
		boost::progress_timer t;
		for(int i=0; i<1000; ++i)
		{
			cout << '2';
		}
		cout << endl;
	}
}