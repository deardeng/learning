#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <xfunctional>
using namespace boost;
using namespace boost::assign;


int g(int a, int b, int c)
{
	std::cout << "in g()" << "a = " << a << " b = " << b << " c = " << c << std::endl;
	return 0;
}

int main()
{
	int xy = 10;
	std::cout << bind(g, _1, boost::cref(xy), boost::ref(xy))(110) << std::endl;
	//f fa;
	//std::cout << bind<int>(ref(af), _1, _2)(10, 20) << std::endl;
	
	std::cout << "*****************************" << std::endl;
	int x = 10;
	BOOST_AUTO(r, ref(x));
	{
		int *y = new int(20);
		r = ref(*y);
		std::cout << r << std::endl;
		std::cout << bind(g, r, 1, 1)() << std::endl;
		std::cout << "*****************************" << std::endl;
		delete y;
	}
	std::cout << bind(g, r, 1, 1)() << std::endl;
	std::cout << "*****************************" << std::endl;


	boost::arg<1> &_x = _1;
	boost::arg<2> &_y = _2;
	boost::arg<1> &arg1 = _1;
	boost::arg<2> &arg2 = _2;

	BOOST_AUTO(&_m, _1);
	BOOST_AUTO(&_n, _2);

	assert(typeid(_x) == typeid(arg1));
	std::cout << "*****************************" << std::endl;

	BOOST_AUTO(bigger, bind(std::greater<int>(), _1, _2));
	std::cout << bigger(10, 20) << std::endl;
	std::cout << std::greater<int>()(30, 20) << std::endl;

}