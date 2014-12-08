#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
using namespace boost;

void any_func(void *p)
{
	std::cout << "some operate" << std::endl;
}


int main()
{
	shared_ptr<void> p((void*)0, any_func);
}