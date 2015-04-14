#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <boost/multi_array.hpp>
#include <cstddef>
#include <stdexcept>
#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <boost/any.hpp>
#include <boost/noncopyable.hpp>
#include <boost/array.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost::property_tree;

typedef basic_ptree<std::string, std::string> ptree;

int main()
{
	typedef basic_ptree<std::string, std::string> ptree;
	using namespace boost::property_tree;
	ptree pt;
	read_json("a.json", pt);

	std::cout << pt.get<std::string>("conf.theme") << std::endl;
	std::cout << pt.get<int>("conf.clock_style") << std::endl;
	std::cout << pt.get<long>("conf.gui") << std::endl;
	std::cout << pt.get("conf.no_prof", 100) << std::endl;

	BOOST_AUTO(child, pt.get_child("conf.urls"));
	for (BOOST_AUTO(pos, child.begin()); pos != child.end(); ++pos)
	{
		std::cout << pos->second.data() << ",";
	}
}