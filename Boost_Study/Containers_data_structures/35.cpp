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
	read_xml("changeconf.xml", pt);
	std::cout << pt.get<std::string>("conf.<xmlcomment>") << std::endl;
	std::cout << pt.get<std::string>("conf.clock_style.<xmlattr>.name") << std::endl;
	std::cout <<  pt.get<long>("conf.theme.<xmlattr>.id") << std::endl;
	std::cout << pt.get<std::string>("conf.urls.<xmlcomment>") << std::endl;

}