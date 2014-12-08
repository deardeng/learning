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

struct demo_class
{
public:
	int a, b, c;
	demo_class(int x=1, int y=2, int z=3):a(x), b(y), c(z){}
};

int main()
{
	object_pool<demo_class> p1;
	demo_class *p = p1.malloc();
	assert(p1.is_from(p));

	assert(p->a !=1 || p->b != 2 || p->c !=3);
	
	p=p1.construct(7, 8, 9);
	assert(p->a == 7);
	object_pool<std::string> pls;
	for(int i=0; i<10; ++i)
	{
		std::string *ps = pls.construct("hello object_pool");
		std::cout << *ps << std::endl;
	}
}