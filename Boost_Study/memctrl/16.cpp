#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/singleton_pool.hpp>
using namespace boost;

struct pool_tag{};
typedef singleton_pool<pool_tag, sizeof(int)> sp1;
int main()
{
	int *p = (int *)sp1::malloc();
	assert(sp1::is_from(p));
	sp1::release_memory();
}