#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/tuple/tuple.hpp>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/ref.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
//using namespace std;
using namespace boost;


typedef tuple<int, std::string> my_tuple1;
typedef tuple<int, my_tuple1> my_tuple2;
typedef tuple<int, double, std::string> my_tuple;

template<typename T>
void print(T& cb)
{
	for (BOOST_AUTO(pos, cb.begin()); pos != cb.end(); ++pos)
	{
		cout << *pos << ",";
	}
	cout << endl;
}

my_tuple func()
{
	return boost::make_tuple(1, 2.0, "string");
}

int main()
{
	int i;
	double d;
	std::string s;
	tie(i, d, s) = func();
	std::cout << i << std::endl;

	double f;
	tie(tuples::ignore, f, boost::tuples::ignore) = func();
	std::cout << f << std::endl;
}