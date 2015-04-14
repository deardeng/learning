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
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace boost::property_tree;

typedef basic_ptree<std::string, std::string> ptree;

int main()
{
	typedef basic_ptree<std::string, std::string> ptree;
	ptree pt;
	try
	{
		read_xml("ac.xml", pt, xml_parser::no_concat_text
			| xml_parser::no_comments | xml_parser::trim_whitespace);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}