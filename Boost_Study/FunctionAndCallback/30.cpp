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
#include <numeric>
#include <boost/random.hpp>
using namespace boost;
using namespace boost::assign;
using namespace boost::signals2;

class demo_class
{
    public:
        typedef boost::signals2::signal<void()> signal_t;
        shared_ptr<signal_t> sig;
        int x;
        demo_class() : sig(new signal_t), x(10){}
};

void print()
{
    std::cout << "hello sig." << std::endl;
}

int main()
{
    demo_class obj;
    assert(obj.sig.use_count() == 1);
    demo_class obj2(obj);
    assert(obj.sig.use_count() == 2);

    obj.sig->connect(&print);
    (*obj2.sig)();
}
