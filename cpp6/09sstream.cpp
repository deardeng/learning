#include <iostream>
using namespace std;
#include <string>
#include <sstream>
class Point{
	int x;
	int y;
public:
	Point(int x, int y):x(x),y(y){}
	friend ostream& operator<<(ostream& o, const Point& p){
		return o << '(' << p.x << ',' << p.y << ')';
	}
};
int main()
{
	string s="12345 6.78 x hello 234 100";
	istringstream is(s);
	int a, b, c;
	double d;
	char e;
	char buf[100];
	is >> a >> d;
	is >> e >> buf >> oct >> b >> hex >> c;
	cout << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << ", e=" << e << ", buf=" << buf << endl;
	ostringstream os;
	Point p(3,5);
	os << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << ", e=" << e << ", buf=" << buf << ", p=" << p;
	cout << "===========" << endl;
	cout << os.str() << endl;
	cout << os.str()[4] << endl;
	cout << "===========" << endl;
} 
