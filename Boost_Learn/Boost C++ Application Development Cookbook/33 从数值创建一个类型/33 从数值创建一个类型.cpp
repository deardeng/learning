#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pod.hpp>

//// ͨ��ʵʩ
//template <class T>
//T process(const T& val)
//{
//	BOOST_STATIC_ASSERT((boost::is_pod<T>::value));
//	// ...
//}

#include <boost/mpl/int.hpp>

namespace detail
{
	// ͨ��ʵ��
	template <class T, class Tag>
	T process_impl(const T& val, Tag /*ignore*/)
	{
		// ...
		BOOST_STATIC_ASSERT(sizeof(val) != 1
			&& sizeof(val) != 4
			&& sizeof(val) != 8
			);
		return val;
	}

	// 1�ֽ��Ż�ʵ��
	template <class T>
	T process_impl(const T& val, boost::mpl::int_<1> /*ignore*/)
	{
		// ...
		BOOST_STATIC_ASSERT(sizeof(val) == 1);
		return val;
	}

	// 4�ֽ��Ż�ʵ��
	template <class T>
	T process_impl(const T& val, boost::mpl::int_<4> /*ignore*/)
	{
		// ...
		BOOST_STATIC_ASSERT(sizeof(val) == 4);
		return val;
	}

	// 8�ֽ��Ż�ʵ��
	template <class T>
	T process_impl(const T& val, boost::mpl::int_<8> /*ignore*/)
	{
		// ...
		BOOST_STATIC_ASSERT(sizeof(val) == 8);
		return val;
	}
} // namespace detail

// ��ֻ���ȵ���
template <class T>
T process(const T& val)
{
	BOOST_STATIC_ASSERT((boost::is_pod<T>::value));
	return detail::process_impl(val, boost::mpl::int_<sizeof(T)>());
}

template <int Value>
struct int_
{
	static const int value = Value;
	typedef int_<Value> type;
	typedef int value_type;
};

#include <iostream>

int main()
{
	process(1);
	process(double());
	process(float());
	process(char());
	process(unsigned());
	process(short());

	std::cout << "short : " << sizeof(short) << std::endl;
	std::cout << "float : " << sizeof(float) << std::endl;
	system("pause");
	return 0;
}