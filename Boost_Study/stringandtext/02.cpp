#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>

#include <boost/lexical_cast.hpp>
using namespace boost;
using namespace std;

int main()
{
	try
	{
		cout << lexical_cast<int>("0x100");
		cout << lexical_cast<double>("HelloWorld");
		cout << lexical_cast<long>("1000L");
		cout << lexical_cast<bool>("false") << endl;
	}
	catch(bad_lexical_cast& e)
	{
		cout << "error:" << e.what() << endl;
	}
}