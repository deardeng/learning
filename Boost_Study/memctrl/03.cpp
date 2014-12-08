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
	shared_ptr<int> spi(new int);
	assert(spi);
	*spi = 253;
	spi = 0;
	assert(!spi);
	shared_ptr<std::string> sps(new std::string("smart"));
	assert(sps->size() == 5);


	typedef shared_ptr<std::string> sp_t;
	std::map<sp_t, int> m;
	sp_t sp(new std::string("one"));
	m[sp] = 111;

	shared_ptr<std::exception> sp1(new std::bad_exception("error"));
	shared_ptr<std::bad_exception> sp2 = dynamic_pointer_cast<std::bad_exception>(sp1);
	shared_ptr<std::exception> sp3 = static_pointer_cast<std::exception>(sp2);
	assert(sp3 == sp1);
}