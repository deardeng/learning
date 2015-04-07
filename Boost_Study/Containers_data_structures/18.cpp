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

//template<typename T>
//void print(T& cb)
//{
//	for (BOOST_AUTO(pos, cb.begin()); pos != cb.end(); ++pos)
//	{
//		cout << *pos << ",";
//	}
//	cout << endl;
//}

template <typename Tuple>
void print_tuple(const Tuple& t)
{
	std::cout << t.get_head() << ",";
	print_tuple(t.get_tail());
}

void print_tuple(const boost::tuples::null_type&){}

template < typename Visitor, typename Tuple>
typename Visitor::result_type
visit_tuple(Visitor v, const Tuple &t)
{
	v(t.get_head());
	return visit_tuple(v, t.get_tail());
}

struct print_visitor
{
	typedef void result_type;
	template<typename T>
	result_type operator()(const T &t)
	{
		std::cout << t << ",";
	}
};

template<>
void visit_tuple(print_visitor, const tuples::null_type &)
{

}
int main()
{
	tuple<int, double, std::string> t(1, 2.1, "string visitor");
	visit_tuple(print_visitor(), t);
}