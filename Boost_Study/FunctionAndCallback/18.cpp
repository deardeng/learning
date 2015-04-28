#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <boost/rational.hpp>
#include <boost/function.hpp>
#include <boost/signals2.hpp>
#include <boost/signal.hpp>
using namespace boost;
using namespace boost::assign;
using namespace boost::signals2;

void slots1()
{
	std::cout << "slot1 called" << std::endl;
}

void slots2()
{
	std::cout << "slot2 called" << std::endl;
}

int main()
{

	boost::signal<void()> sig;
    sig.connect(&slots1);
    sig.connect(&slots2);
    sig();
}
