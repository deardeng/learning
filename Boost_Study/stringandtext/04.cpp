#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>

#include <boost/format.hpp>
using namespace boost;
using namespace std;

int main()
{
	cout << format("%s:%d+%d=%d\n")%"sum" % 1 % 2 % (1+2);
	format fmt("(%1% + %2%) * %2% = %3%\n");
	fmt % 2 % 5;
	fmt % ((2+5)*5);
	cout << fmt.str();

	format fmt1("%05d\n%-8.3f\n% 10s\n%05X\n");
	cout << fmt1 %62 % 2.236 % "123456789" %48;
	format fmt2("%|05d|\n%|-8.3f|\n%|10s|\n%|05X|\n");
	cout << fmt2 %62 % 2.236 % "123456789" %48;

	const format fmt3("%10d %020.8f %010X %10.5e\n");
	cout << format(fmt3) << endl;
}