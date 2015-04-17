#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <boost/multi_array.hpp>
#include <cstddef>
#include <stdexcept>
#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/unordered_set.hpp>
#include <boost/integer_traits.hpp>
#include <boost/cstdint.hpp>
#include <limits>
#include <boost/integer.hpp>
#include <boost/format.hpp>
#include <boost/rational.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/operators.hpp>
#include <boost/algorithm/minmax.hpp>
#include <boost/random.hpp>
#include <ctime>
#include <boost/serialization/singleton.hpp>
using namespace boost;
using boost::serialization::singleton;

template<typename T>
class rng_wraper
{
private:
	T rng;
public:
	rng_wraper() :rng((typename T::result_type)time(0)){}
	typename T::result_type operator()()
	{
		return rng();
	}
};

int main()
{
	typedef singleton<rng_wraper<mt19937> > rng_t;
	rng_wraper<mt19937> &rnt = rng_t::get_mutable_instance();
	for (int i = 0; i < 100; ++i)
	{
		std::cout << rnt() << ",";
	}
}