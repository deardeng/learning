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
using namespace boost;
using namespace boost::assign;
using namespace boost::signals2;

template<typename T>
class combiner
{
    T v;
    public:
    typedef std::pair<T, T> result_type;
    combiner(T t = T()) : v(t){}
    template<typename InputIterator>
        result_type operator() (InputIterator begin, InputIterator end) const
        {
            if(begin == end)
            {
                return result_type();
            }
            std::vector<T> vec(begin, end);
            T sum = std::accumulate(vec.begin(), vec.end(), v);
            T max = *std::max_element(vec.begin(), vec.end());
            return result_type(sum, max);
        }
};

template<int N>
struct slots
{
    int operator()(int x)
    {
        std::cout << "slot" << N << " called" << std::endl;
        return x * N;
    }
};

template<int N>
bool operator==(const slots<N>&, const slots<N>&)
{
    return true;
}


int main()
{
    boost::signals2::signal<int(int) > sig;
    boost::signals2::connection c1 = sig.connect(0, slots<10>());
    boost::signals2::connection c2 = sig.connect(0, slots<20>());
    assert(sig.num_slots() == 2);
    sig(2);

    std::cout << "begin blocking ... " << std::endl;
    {
        //signals2
        boost::signals2::shared_connection_block block(c1);
        assert(sig.num_slots() == 2);
        assert(c1.blocked());
        sig(2);
    }
    std::cout << "end blocking ..." << std::endl;
    assert(!c1.blocked());
    sig(2);
}
