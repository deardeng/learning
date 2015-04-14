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
#include <boost/algorithm/minmax.hpp>
using namespace boost;

template<typename T>
void minmax_swap(T &a, T &b)
{
	if (a > b) swap(a, b);
}

int main()
{
	int a, b;
	tie(a, b) = minmax(5, 3);
	std::cout << a << ":" << b << std::endl;
	std::cout << "***************************" << std::endl;
	int c = 100, d = 50;
	minmax_swap(c, d);
	std::cout << c << ":" << d << std::endl;

}
