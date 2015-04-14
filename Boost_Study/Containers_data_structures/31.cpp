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
#include <boost/any.hpp>
#include <boost/noncopyable.hpp>
#include <boost/array.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>

using namespace boost;

template<typename T, std::size_t N>
class multi_bulider : boost::noncopyable
{
private:
	boost::array<std::size_t, N> d;
public:
	typedef boost::multi_array<T, N> array_type;
	typedef boost::shared_ptr<array_type > type;

	multi_bulider(){}
	~multi_bulider(){}

	template<std::size_t n>
	void dim(std::size_t x)
	{
		BOOST_STATIC_ASSERT(n >= 0 && n < N);
		d[n] = x;
	}
	//type create()
	//{
	//	return type(new array_type(d));
	//}
	//} 
	type create()
	{
		typedef boost::detail::multi_array::extent_gen<N> gen_type;
		gen_type r;

		for (int i = 0; i != N; ++i)
		{
			typedef typename gen_type::range_type;
			r.ranges_[i] = range_type(0, d[i]);
		}
		return type(new array_type(r));
	}
};

int main()
{
	typedef multi_array<int, 3> ma_type;
	typedef ma_type::extent_range range;
	ma_type ma(extents[range(1, 5)][4][range(-2, 2)]);
	ma[1][0][-2] = 10;

	ma.reindex(1);
	assert(ma[1][1][1] == 10);
	ma.reindex(array < size_t, 3>(assign::list_of(1)(0)(-4)));
	assert(ma[1][0][-4] == 10);

	std::cout << *ma.index_bases() << std::endl;

	typedef multi_array<int, 3> ma_type;
	typedef ma_type::index_range range1;
	ma_type ma1(extents[9][8][7]);
	BOOST_AUTO(view, ma1[indices[range1() < 3][2 <= range1() <= 5][range1()]]);
	std::cout << *view.shape() << std::endl;
}