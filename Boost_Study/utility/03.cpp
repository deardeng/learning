#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/optional.hpp>
using namespace boost;

int main()
{
	optional<int> op0;
	optional<int> op1(none);
	assert(!op0);
	assert(op0 == op1);
	assert(op0.get_value_or(2523) == 2523);

	optional<std::string> ops("test");
	std::cout << *ops << std::endl;

	std::vector<int> v(10);
	optional<std::vector<int>& > opv(v);
	assert(opv);

	opv->push_back(5);
	assert(opv->size() == 11);

	opv = none;
	assert(!opv);
}