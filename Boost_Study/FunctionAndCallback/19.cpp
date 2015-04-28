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
    void operator()()
    {
        std::cout << "slot" << N << " called" << std::endl;
    }
};

int main()
{
	boost::signal<void()> sig;
    sig.connect(slots<1>());
    sig.connect(slots<100>());
    sig.connect(5, slots<51>());
    sig.connect(5, slots<55>());
    sig.connect(3, slots<30>());
    sig.connect(3, slots<33>());
    sig.connect(3, slots<10>());
    sig();
}
