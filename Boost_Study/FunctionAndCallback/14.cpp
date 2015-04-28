#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <boost/rational.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::assign;

template<typename T>
struct summary
{
	typedef void result_type;
	T sum;
	summary(T v = T()) : sum(v){}
	void operator()(T const &x)
	{
		sum += x;
	}
};

int main()
{
	using namespace boost::assign;
	std::vector<int> v = (list_of(1), 3, 5, 7, 9);
	summary<int> s;
	function<void(int const&)> func(ref(s));
	std::for_each(v.begin(), v.end(), func);
	std::cout << s.sum << std::endl;
}