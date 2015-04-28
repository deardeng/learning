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

template<int N>
struct slots
{
    int operator()(int x)
    {
        std::cout << "slot" << N << " called" << std::endl;
        return x * N;
    }
};

int main()
{
	boost::signal<int(int)> sig;
    sig.connect(slots<10>());
    sig.connect(slots<20>());
    sig.connect(slots<50>());
    std::cout << (sig(2)) << std::endl;
}
