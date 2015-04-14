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
#include <vector>

using namespace boost;

int main()
{
	multi_array<int, 3> maa(extents[2][3][4]);
	assert(maa.shape()[0] == 2);
	array<std::size_t, 3> arr = { 4, 3, 2 };
	maa.reshape(arr);
	assert(maa.shape()[0] == 4);

	maa.resize(extents[2][9][9]);
	assert(maa.num_elements() == 2 * 9 * 9);
	assert(maa.shape()[1] == 9);

	typedef multi_array<int, 2> ma_type;
	multi_array<int, 2> ma(extents[3][4]);
	for (int i = 0, v = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ma[i][j] = v++;
		}
	}

	typedef ma_type::index_range range;
	BOOST_AUTO(view, ma[indices[range(0, 2)][range(0, 4, 2)]]);
	ma_type::array_view<2>::type view1 = ma[indices[range(0, 2)][range(0, 2)]];

	std::cout << view.num_elements() << std::endl;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			std::cout << view[i][j] << ",";
	std::cout << std::endl;
	std::cout << *view.shape() << std::endl;

	BOOST_AUTO(view2, ma[indices[1][range(0, 4)]]);
	for (int i = 0; i < 4; ++i)
		std::cout << view2[i] << ",";
	std::cout << std::endl;

	int arrr[12];
	for (int i = 0; i < 12; ++i)
	{
		arrr[i] = i;
	}

	multi_array_ref<int, 2> mar(arrr, extents[3][4]);
	for (size_t i = 0; i < 3; ++i)
	{
		std::cout << "(";
		for (size_t j = 0; j < 4; ++j)
		{
			std::cout << mar[i][j]++;
			std::cout << (j != 3 ? ',' : ' ');
		}
		std::cout << ")" << std::endl;
	}

	const_multi_array_ref<int, 2> cmar(arrr, extents[2][6]);
	for (size_t i = 0; i < 2; ++i)
	{
		std::cout << "(";
		for (size_t j = 0; j < 6; ++j)
		{
			std::cout << cmar[i][j];
			std::cout << (j != 5 ? ',' : ' ');
		}
		std::cout << ")" << std::endl;
	}

	array<std::size_t, 3> arr1 = { 2, 3, 4 };
	multi_array<int, 3> ma1(arr1);

	multi_array<int, 3> ma2(std::vector<int>(assign::list_of(2) (2) (3)));
}