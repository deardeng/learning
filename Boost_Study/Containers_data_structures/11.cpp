#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/circular_buffer.hpp>
#include <hash_set>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
using namespace std;
using namespace boost;

template<typename T>
void print(T& cb)
{
	for (BOOST_AUTO(pos, cb.begin()); pos != cb.end(); ++pos)
	{
		cout << *pos << ",";
	}
	cout << endl;
}

int main()
{
	using namespace boost::assign;

	circular_buffer_space_optimized<int> cb(10);
	push_back(cb) (1), 2, 3, 4;
	assert(cb.size() == 4);
	assert(cb.capacity() == 10);

	cb.resize(100, 4);
	print(cb);
	std::cout << "size = " << cb.size() << std::endl;
	assert(cb.size() == cb.capacity());
}