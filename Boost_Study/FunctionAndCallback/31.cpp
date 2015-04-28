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

template<int N>
struct slots
{
    int operator()(const connection& conn, int x)
    {
        std::cout << "conn= " << conn.connected() << std::endl;
        return x * N;
    }
};

int main()
{
    typedef boost::signals2::signal<int(int) > signal_t;
    typedef signal_t::extended_slot_type slot_t;
    signal_t sig;

    sig.connect_extended(slot_t(&slots<10>::operator(), slots<10>(), _1, _2));
    sig.connect_extended(slot_t(&slots<20>::operator(), slots<20>(), _1, _2));

    sig(5);
}
