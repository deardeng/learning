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
	vector<string> v(100, "aaa");
	v[10] = "";
	v[23] = "";
	ofstream fs("d:\\test.txt");
	progress_display pd(v.size());
	vector<string>::iterator pos;
	for(pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << endl;
		//++pd;
		pd.restart(v.size());
		pd += (pos - v.begin() + 1);
		if(pos->empty())
		{
			cout << "null string # "
				<< (pos - v.begin()) << endl;
		}
	}

}