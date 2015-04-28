#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
using namespace boost;

template<typename T, typename T1>
typename result_of<T(T1)>::type call_func(T t, T1 t1)
{
	return t(t1);
}

int main()
{
	typedef double(*Func) (double d);
	Func func = sqrt;
	result_of<Func(double)>::type x = func(5.0);
	std::cout << typeid(x).name() << std::endl;
	BOOST_AUTO(xx, call_func(func, 5.0));
	std::cout << typeid(xx).name() << std::endl;
}