#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
using namespace boost;

int main()
{
	shared_ptr<int> sp(new int(10));
	assert(sp.use_count() == 1);

	weak_ptr<int> wp(sp);
	assert(wp.use_count() == 1);
	std::cout << *sp << std::endl;

	if(!wp.expired())
	{
		shared_ptr<int> sp2 = wp.lock();
		*sp2 = 100;
		assert(wp.use_count() == 2);
	}

	assert(wp.use_count() == 1);
	sp.reset();
	assert(wp.expired());
	assert(!wp.lock());
}