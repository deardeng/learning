#include <cstring>
#include <boost/array.hpp>

// ��δ������������⣺
//		δ��黺�����Ĵ�С���������������
//		�˺������ܱ����ڷǴ������ݣ�POD�����ͣ��⽫���²���ȷ����Ϊ
// ͨ������һЩ���ԣ����ܽ����������

template <class T, std::size_t BufSizeV>
void serialize_bad(const T& value, boost::array<unsigned char, BufSizeV>& buffer)
{
	assert(BufSizeV >= sizeof(value));
	// TODO:fixme
	std::memcpy(&buffer[0], &value, sizeof(value));
}
// ���ǣ�����һ�����Ľ��������BufSizeV �� sizeof(value)��ֵ�ڱ���ʱ��֪��
// ���������������С����δ����п��ܱ���ʧ�ܣ���������һ������ʱ���ԣ����δ���ú�����
// ���ܲ����ڵ��ù����д����������������ڷֲ�ģʽ���Ż��������Կ��ܻᷢ���ǳ��������飩


#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pod.hpp>

template <class T, std::size_t BufSizeV>
void serialize(const T& value, boost::array<unsigned char, BufSizeV>& buffer)
{
	BOOST_STATIC_ASSERT(BufSizeV >= sizeof(value));
	BOOST_STATIC_ASSERT(boost::is_pod<T>::value);

	std::memcpy(&buffer[0], &value, sizeof(value));
}

BOOST_STATIC_ASSERT(3 >= 1);

struct some_struct
{
	enum enum_t{ value = 1};
};
BOOST_STATIC_ASSERT(some_struct::value);

template <class T1, class T2>
struct some_templated_struct
{
	enum enum_t { value = (sizeof(T1) == sizeof(T2)) };
};
BOOST_STATIC_ASSERT((some_templated_struct<int, unsigned int>::value));

#include <iostream>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

template <class T1, class T2>
void type_traits_examples(T1& /*v1*/, T2& /*v2*/)
{
	// ���T1��һ���޷�����������true
	std::cout <<  std::boolalpha << boost::is_unsigned<T1>::value << std::endl;

	// ���T1��T2������ȫ��ͬ�����ͣ�����true
	std::cout << boost::is_same<T1, T2>::value << std::endl;

	// ����ɾ��T1���͵�const���η�
	// �����ǽ�������T1�����ϵģ����T1�ǣ�
	// const int => int
	// int => int
	// int const valatile => int volatile
	// const int& => const int&
	typedef typename boost::remove_const<T1>::type t1_nonconst_t;
}

template <class T, std::size_t BufSizeV>
void serialize2(const T& value, boost::array<unsigned char, BufSizeV>& buf)
{
	BOOST_STATIC_ASSERT_MSG(boost::is_pod<T>::value,
		"This serialize2 function may be used only "
		"with POD types."
		);

	BOOST_STATIC_ASSERT_MSG(BufSizeV >= sizeof(value),
		"Can not fit value to buffer. "
		"Make buffer bigger."
		);

	std::memcpy(&buf[0], &value, sizeof(value));
}

int main()
{
	const int i = 1;
	type_traits_examples(i, i);

	// Somewhere in code:
	boost::array<unsigned char, 1> buf;
	// serialize2(std::string("Hello word"), buf);

	(void)buf;

	system("pause");
	return 0;
}