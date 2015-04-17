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

//1
template<typename Rng>
void rand_bytes(unsigned char* buf, int buf_len)
{
	typedef variate_generator<Rng, uniform_smallint<> > var_gen;
	static var_gen gen(Rng((typename Rng::result_type)std::time(0)), uniform_smallint<>(1, 255));

	for (int i = 0; i < buf_len; ++i)
	{
		buf[i] = gen();
	}
}


//2 无法通过编译error C4996: 'std::_Generate_n': Function call with parameters that may be unsafe - this call relies on the caller to check that the passed values are correct. To disable this warning, use -D_SCL_SECURE_NO_WARNINGS. See documentation on how to use Visual C++ 'Checked Iterators'
// 1 > c:\program files(x86)\microsoft visual studio 12.0\vc\include\algorithm(1542) : 参见“std::_Generate_n”的声明
//template<typename Rng>
//void rand_bytes(unsigned char* buf, int buf_len)
//{
//	typedef variate_generator<Rng, uniform_smallint<> > var_gen;
//	static var_gen gen(Rng((typename Rng::result_type)std::time(0)), uniform_smallint<>(1, 255));
//
//	class var_wrapper
//	{
//	public:
//		var_wrapper(var_gen &t_) :t(&t_){}
//		typename var_gen::result_type operator()()
//		{
//			return (*t)();
//		}
//	private:
//		var_gen *t;
//	};
//	//std::generate_n(buf, buf_len, var_wrapper(gen));
//
//	//std::generate_n(buf, buf_len, std::tr1::ref(gen));
//
//	//std::generate_n(buf, buf_len, boost::ref(gen));
//}

int main()
{
	unsigned char buf[10];

	rand_bytes<mt19937>(buf, 10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << (short)buf[i] << ",";
	}
	std::cout << std::endl;

	rand_bytes<rand48>(buf, 10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << (short)buf[i] << ",";
	}
	std::cout << std::endl;
}