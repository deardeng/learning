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
	assert(sp.unique());
	shared_ptr<int> sp2 = sp;
	assert(sp == sp2 && sp.use_count() == 2);

	*sp2 = 100;
	assert(*sp == 100);
	
	sp.reset();
	assert(!sp);
}