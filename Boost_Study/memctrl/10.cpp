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
	int *p = new int[100];
	shared_array<int> sa(p);
	shared_array<int> sa2 = sa;

	sa[0] = 10;
	assert(sa2[0] == 10);

	std::cout << sa.use_count() << std::endl;
	std::cout << p[0] << std::endl;
}