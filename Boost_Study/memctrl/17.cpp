#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/pool/pool_alloc.hpp>
using namespace boost;

int main()
{
	std::vector<int, pool_allocator<int>>v;
	v.push_back(10);
	std::cout << v.size() << std::endl;
}