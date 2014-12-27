#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <boost/format.hpp>
using namespace boost;
using boost::io::group;
using namespace std;

int main()
{
	format fmt("%1% %2% %3% %2% %1% \n");
	cout << fmt % 1 % 2 % 3;

	fmt.bind_arg(2, 10);
	cout << fmt %1 %3;

	fmt.clear();

	cout << fmt %group(showbase, oct, 111) %333;

	fmt.clear_binds();

	fmt.modify_item(1, group(hex, right, showbase, setw(8), setfill('*')));
	cout << fmt % 49 % 20 % 100;
}