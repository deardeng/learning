#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/serialization/singleton.hpp>
using boost::serialization::singleton;
using namespace std;

class point
{
public:
	point(int a=0, int b=0, int c=0):x(a), y(b), z(c)
	{
		cout << "point ctor" << endl;
	}
	~point()
	{
		cout << "point dtor" << endl;
	}
	void print() const
	{
		cout << "1point...." << endl;
	}
	void print()
	{
		cout << "2point...." << endl;
	}
private:
	int x, y, z;
};

int main()
{
	cout << "main() start" << endl;
	typedef singleton<point> origin;

	origin::get_const_instance().print();
	origin::get_mutable_instance().print();

	cout << "main() finish" << endl;

}