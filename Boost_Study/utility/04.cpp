#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/typeof/typeof.hpp>
#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
using namespace boost;

optional<double> calc(int x)
{
	return optional<double>(x != 0, 1.0/x);
}

optional<double> sqrt_op(double x)
{
	return optional<double>(x > 0, sqrt(x));
}

int main()
{
	optional<double> d = calc(10);
	if(d)
	{
		std::cout << *d << std::endl;
	}

	d = sqrt_op(-10);
	std::cout << d << std::endl;
	if(!d)
	{
		std::cout << "no result" << std::endl;
	}

	BOOST_AUTO(x, make_optional(5));
	assert(*x == 5);

	BOOST_AUTO(y, make_optional<double>((*x > 10), 1.0));
	assert(!y);


	optional<std::string> ops(in_place("test in_place_factory"));
	std::cout << *ops <<std::endl;;

	optional<std::vector<int> > opp(in_place(10, 3));
	assert(opp->size() == 10);
	assert((*opp)[0] == 3);
}