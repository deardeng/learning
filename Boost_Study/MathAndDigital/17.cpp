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
#include <boost/nondet_random.hpp>
using namespace boost;

class boost::random_device::impl
{
private:
	rand48 rng;
public:
	impl() : rng(time(0))
	{
		std::cout << "random_device::impl ctor\n";
	}
	~impl()
	{
		std::cout << "random_device::impl dtor\n";
	}
	unsigned int operator()()
	{
		return rng();
	}

};

const char* const default_token = "some_device";

boost::random_device::random_device(const std::string& token) : pimpl(new impl)
{

}

boost::random_device::~random_device()
{
	delete pimpl;
}

double boost::random_device::entropy() const
{
	return 10;
}

unsigned int boost::random_device::operator ()()
{
	return (*pimpl)();
}

int main()
{
	random_device rng(default_token);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << rng() << ",";
	}
	std::cout << std::endl;

	uniform_real<> ur(1.0, 2.0);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << ur(rng) << ",";
	}
	std::cout << std::endl;

	variate_generator< random_device&, uniform_smallint<> > gen(rng, uniform_smallint<>(0, 255));
	for (int i = 0; i < 10; ++i)
	{
		std::cout << gen() << ",";
	}
	std::cout << std::endl;
}