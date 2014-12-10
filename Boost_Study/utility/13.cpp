#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>

#include <boost/logic/tribool_io.hpp>
using namespace boost;
using namespace std;


class demo_class
{
public:
	demo_class(int n):x(n){}
	int x;
	friend bool operator<(const demo_class& l, const demo_class& r)
	{
		return l.x < r.x;
	}
	bool operator>(const demo_class& r)
	{
		return this->x > r.x;
	}
};

int main()
{
	tribool tb1(true), tb2(false), tb3(indeterminate);
	
	cout << boolalpha <<  tb1 << "," << tb2 << "," << tb3 << endl;

	demo_class a(10), b(20), c(30);
	cout << (c>a) << endl;
	using namespace std::rel_ops;
	cout << (a<b) << endl;
	cout << (b>=a) << endl;

}