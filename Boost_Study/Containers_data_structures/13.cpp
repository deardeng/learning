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

	my_tuple t1;
	my_tuple t2(1, "123");
	my_tuple t3(t1);
	t2 = t3;

	int x = 10;
	tuple<int&> t4(x);
	tuple<int&> t5(x);


	int i;
	std::string s;
	boost::tuple<int, std::string&> t8 = boost::make_tuple(i, boost::ref(s));
	boost::tuple<const int&, std::string&> t9 = boost::make_tuple(cref(i), boost::ref(s));
}