#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <xfunctional>
#include <boost/rational.hpp>
using namespace boost;
using namespace boost::assign;

int main()
{
	typedef boost::rational<int> ri;
	std::vector<ri> v = list_of(ri(1, 2)) (ri(3, 4)) (ri(5, 6));

	remove_if(v.begin(), v.end(), bind(&ri::numerator, _1) == 1);
	assert(v[0].numerator() == 3);

	assert(find_if(v.begin(), v.end(), bind(&ri::numerator, _1) == 1) == v.end());

	BOOST_AUTO(pos, find_if(v.begin(), v.end(), bind(&ri::numerator, _1) > 3 && bind(&ri::denominator, _1) < 8));

	std::cout << *pos << std::endl;

	struct pred
	{
		bool operator()(ri &r)
		{
			return r.numerator() > 3 && r.denominator() < 8;
		}
	};

	pos = find_if(v.begin(), v.end(), pred());
	std::cout << *pos << std::endl;

	std::cout << bind<int>(printf, "%d+%d=%d\n", _1, 3, _2)(6, 7) << std::endl;
}