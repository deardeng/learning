#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
using namespace boost;

template<typename P, typename T0, typename T1, typename T2, typename T3> inline typename P::element_type*
	construct(P& p, const T0& a0, const T1& a1, const T2& a2, const T3& a3)
{
	typename P::element_type* mem = p.malloc();
	assert(mem != 0);
	new (mem) P::element_type(a0, a1, a2, a3);
	return mem;
}

struct demo_class
{
	demo_class(int, int, int, int)
	{
		std::cout << "demo_class ctor" << std::endl;
	}
	~demo_class()
	{
		std::cout << "demo_class dtor" << std::endl;
	}
};

int main()
{
	object_pool<demo_class> p1;
	demo_class* d2 = construct(p1, 1, 2, 3, 4);
}