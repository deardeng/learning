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
	typedef tuple<int, double, std::string> my_tuple;
	//my_tuple t1(1, 2.0, "string");
	//std::cout << t1 << std::endl;
	//std::cout << "please input tuple:";
	//std::cin >> t1;
	//std::cout << t1 << std::endl;
	//
	my_tuple t2(1, 2.0, "string");
	std::cout << tuples::set_open('[') << tuples::set_close(']');
	std::cout << tuples::set_delimiter(',');
	std::cin >> t2;
	std::cout << t2 << std::endl;
	std::cout << t2 << std::endl;
}