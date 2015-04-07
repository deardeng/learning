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

template <typename Tuple>
void print_tuple(const Tuple& t)
{
	std::cout << t.get_head() << ",";
	print_tuple(t.get_tail());
}

void print_tuple(const boost::tuples::null_type&){}

int main()
{
	typedef tuple<int, double, std::string> my_tuple;
	using namespace boost::assign;
	my_tuple t(1, 3.1, "string tuple");
	print_tuple(t);
	std::cout << std::endl;
	std::vector<my_tuple> v = tuple_list_of(1, 1.0, "123") (2, 2.0, "456");
	assert(v.size() == 2);
	int a = 7; double b = 3.4; std::string c = "ade";
	v += make_tuple(3, 3.0, "789"), make_tuple(4, 4.0, "abc"), tie(a, b, c);
	assert(v.size() == 5);
}