#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/assign.hpp>
#include <boost/operators.hpp>
#include <boost/typeof/typeof.hpp>
using namespace boost;
using namespace std;

class point : totally_ordered<point, additive<point> >
{
	int x, y, z;
public:
	explicit point(int a=0, int b=0, int c=0):x(a),y(b),z(c){}
	void print()const
	{
		cout << x << "," << y << "," << z << endl;
	}
	friend bool operator<(const point&l, const point& r)
	{
		return (l.x*l.x + l.y*l.y + l.z*l.z < r.x*r.x + r.y*r.y + r.z*r.z);
	}
	friend bool operator==(const point& l,const point& r)
	{
		return r.x == l.x && r.y == l.y && r.z == l.z;
	}
	point& operator+=(const point& r)
	{
		x += r.x;
		y += r.y;
		z += r.z;
		return *this;
	}
	point& operator-=(const point& r)
	{
		x -= r.x;
		y -= r.y;
		z -= r.z;
		return *this;
	}
};
int main()
{
	point p0, p1(1, 2, 3), p2(5, 6, 7), p3(3, 2, 1);
	using namespace boost::assign;
	vector<point> v = (list_of(p0), p1, p2, p3);

	BOOST_AUTO(pos, std::find(v.begin(), v.end(), point(1, 2, 3)));
	//pos->print();

	//(p1 + p2).print();
	//(p3 - p1).print();

	//assert((p2 - p2) == p0);

	for(; pos != v.end(); pos = std::find(pos+1, v.end(), point(1, 2, 3)))
	{
		pos->print();
		pos = std::find(v.begin(), v.end(), point(2, 1, 3));
		assert(pos == v.end());
		--pos;
	}
}