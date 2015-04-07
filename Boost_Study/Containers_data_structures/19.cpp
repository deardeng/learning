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

using namespace boost;

template<typename T>
struct max_visitor
{
	T *tmp;
	max_visitor(T *t) : tmp(t){}
	typedef void result_type;
	result_type operator()(const T &t)
	{
		*tmp = *tmp < t ? t : *tmp;
	}
};

template<typename Visitor, typename Tuple>
typename Visitor::result_type
visit_tuple(Visitor v, const Tuple &t)
{
	v(t.get_head());
	return visit_tuple(v, t.get_tail());
}

template<>
void visit_tuple( max_visitor<double>, const tuples::null_type &)
{

}

int main()
{
	tuple<int, long, float, double> t(100, 5, 3.14, 314.15);
	double *max_value = new double(t.get_head());
	max_visitor<double> mv(max_value);
	visit_tuple(mv, t);
	std::cout << *max_value << std::endl;
}