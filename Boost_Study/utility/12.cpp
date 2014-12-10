#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/logic/tribool.hpp>
using namespace boost;
using namespace std;
BOOST_TRIBOOL_THIRD_STATE(unknown);
namespace tmp_ns
{
	BOOST_TRIBOOL_THIRD_STATE(maybe);
};
int main()
{
	tribool tb(true);
	tribool tb2(!tb);

	if(tb)
	{
		cout << "true" << endl;
	}
	tb2 = indeterminate;
	assert(indeterminate(tb2));
	cout << tb2 << endl;
	if(tb2 == indeterminate)
	{
		cout << "indeterminate" << endl;
	}
	cout << (tb2 || true) << endl;
	cout << (tb2 && false) << endl;

	tribool tb3(indeterminate);
	if(tb3)
		cout << "never reach here" << endl;
	if(!tb3)
		cout << "never reach hear" << endl;
	if(indeterminate(tb3))
		cout << "indeterminate" << endl;

	
	tribool tb4(unknown);
	assert(unknown(tb4));
	assert(unknown(tb4 || false));


	tribool tb5(tmp_ns::maybe);
}