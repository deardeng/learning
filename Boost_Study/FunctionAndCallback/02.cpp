#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;


int main()
{
	struct square
	{
		typedef void result_type;
		void operator()(int &x)
		{
			x = x * x;
		}
	};
	std::vector<int> v = (list_of(1), 2, 3, 4, 5);
	for_each(v.begin(), v.end(), square());
}