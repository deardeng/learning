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
	typedef basic_ptree<std::string, std::string> prtree;
	ptree pt;
	read_xml("conf.xml", pt);

	pt.put("conf.theme", "Matrix Reloaded");
	pt.put("conf.clock_style", 12);
	pt.put("conf.gui", 0);
	//pt.add("conf.urls.url", "http://www.url4.org");
	pt.put("conf.urls.url", "http://www.url4.org");

	write_xml(std::cout, pt);
}