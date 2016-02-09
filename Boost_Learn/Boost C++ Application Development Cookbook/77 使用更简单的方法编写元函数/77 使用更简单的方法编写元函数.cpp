// VS2015 对constexpr部分支持，无法编译通过，不过用gnu g+++编译器的code blocks可以编译运行

#include <boost/config.hpp>

#if !defined(BOOST_NO_CXX11_CONSTEXPR)	\
	&& !defined(BOOST_NO_CXX11_HDR_ARRAY)

template <class T>
constexpr int get_size(const T& val)
{
	return val.size() * sizeof(typename T::value_type);
}

template <class T, T Value>
struct integral_constant
{
	BOOST_STATIC_CONSTEXPR T value = Value;
	BOOST_CONSTEXPR operator T() const
	{
		return this->value;
	}
};

char array[integral_constant<int, 10>()];

#else
#error "This code requires C++11 constexpr and std::array"
#endif

#include <array>
#include <cassert>
int main()
{
	std::array<short, 5> arr;
	assert(get_size(arr) == 5 * sizeof(short));

	unsigned char data[get_size(array)];

	assert(sizeof(array) == 10);
	(void)data;

	system("pause");
	return 0;
}
