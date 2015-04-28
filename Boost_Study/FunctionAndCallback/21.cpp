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

int main()
{
    //cout 160, 100
	//boost::signal<int(int), combiner<int> > sig;

    //cout 260, 100
	boost::signal<int(int), combiner<int> > sig(combiner<int>(100));
    sig.connect(slots<10>());
    sig.connect(slots<20>());
    sig.connect(slots<50>());
    BOOST_AUTO(x, sig(2));
    std::cout << x.first << " , " << x.second << std::endl;
}
