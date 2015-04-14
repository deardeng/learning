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
#include <boost/property_tree/xml_parser.hpp>
using namespace boost::property_tree;


int main()
{
	typedef basic_ptree<std::string, std::string> ptree;
	ptree pt;
	read_xml("conf.xml", pt);
	pt.get<std::string>("conf.theme");
	std::cout << pt.get<int>("conf.clock_style") << std::endl;
	std::cout << pt.get("conf.no_prop", 100) << std::endl;

	BOOST_AUTO(child, pt.get_child("conf.urls"));
	for (BOOST_AUTO(pos, child.begin()); pos != child.end(); ++pos)
	{
		std::cout << pos->second.get_value<std::string>() << ",";
	}
}