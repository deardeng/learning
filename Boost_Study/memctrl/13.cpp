#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
#include <boost/pool/pool.hpp>
using namespace boost;


int main()
{
	pool<> p1(sizeof(int));

	int *p = (int *)p1.malloc();
	assert(p1.is_from(p));

	p1.free(p);
	for(int i=0; i<100; ++i)
	{
		p1.ordered_malloc(10);
	}
}