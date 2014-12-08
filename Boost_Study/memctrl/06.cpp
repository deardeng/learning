#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/make_shared.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost;

int main()
{
	shared_ptr<std::string> sp = make_shared<std::string>("make_shared");
	shared_ptr<std::vector<int> > spv = make_shared<std::vector<int> >(10, 2);
	assert(spv->size() == 10);


	typedef std::vector<shared_ptr<int> > vs;
	vs v(10);

	int i = 0;
	for(vs::iterator pos = v.begin(); pos != v.end(); ++pos)
	{
		(*pos) = make_shared<int>(++i);
		std::cout << *(*pos) << ", ";
	}
	std::cout << std::endl;

	shared_ptr<int> p = v[9];
	*p = 100;
	std::cout << *v[9] << std::endl;
}