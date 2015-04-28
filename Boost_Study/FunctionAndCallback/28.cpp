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
    typedef boost::signals2::signal<int(int) > signal_t;
    typedef signal_t::slot_type slot_t;
    signal_t sig;

    shared_ptr<slots<10> > p1(new slots<10>);
    shared_ptr<slots<20> > p2(new slots<20>);

    function<int(int) > func = ref(*p1);
    sig.connect(slot_t(func).track(p1));

    sig.connect(slot_t(&slots<20>::operator(), p2.get(), _1).track(p2));

    p1.reset();
    p2.reset();
    assert(sig.num_slots() == 0);
    sig(1);
}
