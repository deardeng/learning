#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <set>
using namespace boost;
using namespace boost::assign;

struct square
{
	typedef void result_type;
	void operator()(int& x)
	{
		x = x * x;
	}
};

int main()
{
	typedef double(*pfunc) (double);
	pfunc pf = sqrt;
	std::cout << std::ref(pf)(5.0) << std::endl;

	square sq;
	int x = 5;
	std::ref(sq) (x);
	std::cout << x << std::endl;

	std::vector<int> v = { 1, 2, 3, 4, 5 };
	for_each(v.begin(), v.end(), std::ref(sq));
}