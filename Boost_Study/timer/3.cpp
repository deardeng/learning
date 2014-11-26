#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>

#include <fstream>
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
	vector<int> v(10000000);
	vector<int>::iterator ps;
	int i;
	for(ps = v.begin(), i=0; ps != v.end(); ++ps,++i)
	{
		*ps = i;
	}
	ofstream fs("d:\\test.txt");

	progress_display pd(v.size());

	vector<int>::iterator pos;
	for(pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << endl;
		//cout << *pos << endl;
		++pd;
	}
}