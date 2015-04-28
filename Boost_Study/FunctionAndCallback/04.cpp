#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <set>
using namespace boost;
using namespace boost::assign;


int main()
{
	std::set<int> s; 
	BOOST_AUTO(rw, boost::ref(s));
	unwrap_ref(rw).insert(12);

	std::string str("test");
	BOOST_AUTO(rws, boost::cref(str));
	std::cout << unwrap_ref(rws).c_str() << std::endl;
}