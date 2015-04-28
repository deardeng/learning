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


int g(int a)
{
	std::cout << "in g()" << "a = " << a << std::endl;
	return a;
}

int f(int a)
{
	std::cout << "in f()" << "a = " << a << std::endl;
	return a+1;
}
int main()
{
	std::cout << "***************************" << std::endl;
	std::cout << bind(g, _1)(6) << std::endl;
	std::cout << bind(f, _1)(8) << std::endl;
	std::cout << "***************************" << std::endl;
	std::cout << bind(g, bind(f, _1))(8) << std::endl;

}