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
    int operator()(int x)
    {
        std::cout << "slot" << N << " called" << std::endl;
        return x * N;
    }
};

template<typename Signature>
class sig_ex
{
    public:
        typedef boost::signals2::signal<Signature> signal_type;
        typedef typename signal_type::slot_type slot_type;
        connection connect(const slot_type& s)
        {
            return sig.connect(s);
        }
        connection operator+=(const slot_type& s)
        {
            return connect(s);
        }
        typename signal_type::result_type operator()(typename signal_type::template arg<0>::type a0)
        {
            return sig(a0);
        }
    private:
        signal_type sig;
};

int main()
{
    sig_ex<int(int)> sig;

    sig += slots<10>();
    sig += slots<5>();

    sig(2);
}
