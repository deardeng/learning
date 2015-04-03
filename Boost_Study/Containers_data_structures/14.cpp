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
//using namespace std;
using namespace boost;


typedef tuple<int, std::string> my_tuple1;
typedef tuple<int, my_tuple1> my_tuple2;
typedef tuple<int, std::string, double> my_tuple;

template<typename T>
void print(T& cb)
{
	for (BOOST_AUTO(pos, cb.begin()); pos != cb.end(); ++pos)
	{
		cout << *pos << ",";
	}
	cout << endl;
}

int main()
{
	using namespace boost::assign;
	BOOST_AUTO(t, boost::make_tuple(1, "char[]", 100.0));
	assert(t.get<0>() == 1);
	assert(t.get<2>() == 100.0);
	std::cout << t.get<1>() << std::endl;
	std::cout << ++t.get<0>() << std::endl;
	std::cout << boost::get<2>(t) << std::endl;

	typedef tuple<int, double, std::string> my_tuple1;

	my_tuple1 t1 = boost::make_tuple(1, 100.0, std::string("abc"));
	my_tuple1 t2 = boost::make_tuple(1, 200.0, std::string("def"));
	assert(t1 < t2);

	my_tuple1 t3(t2);
	assert(t2 == t3);
}