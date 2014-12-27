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

template<typename T>
bool num_valid(const char* str)
{
	try
	{
		lexical_cast<T>(str);
		return true;
	}
	catch(bad_lexical_cast&)
	{
		return false;
	}
}

//class demo_class
//{
//	friend std::ostream& operator<<(std::ostream& os, const demo_class& x)
//	{
//		os << "demo_class's Name";
//		return os;
//	}
//};

template<typename T>
struct outable
{
	friend std::ostream& operator<<(std::ostream& os, const T& x)
	{
		os <<typeid(T).name();
		return os;
	}
};

class demo_class : outable<demo_class>{};

int main()
{
	assert(num_valid<double>("3.14"));
	assert(!num_valid<int>("3.14"));
	assert(num_valid<int>("65535"));
	//cout << lexical_cast<int>("3.14") << endl;
	cout << lexical_cast<string>(demo_class()) << endl;
}