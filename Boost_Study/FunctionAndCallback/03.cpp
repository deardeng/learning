#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;


int main()
{
	int x = 10;
	reference_wrapper<int> rw(x);
	assert(x == rw);
	(int &)rw = 100;
	assert(x == 100);

	reference_wrapper<int> rw2(rw);
	assert(rw2.get() == 100);
	
	std::string str;
	reference_wrapper<std::string> rws(str);
	*(rws.get_pointer()) = "test reference_wrapper";
	std::cout << rws.get().size() << std::endl;

	double xxx = 2.71828;
	BOOST_AUTO(crw, cref(x));
	std::cout << typeid(crw).name() << std::endl;

	std::string strs;
	BOOST_AUTO(rwss, boost::ref(strs));
	std::cout << typeid(rwss).name() << std::endl;

	double y = 2.0;
	std::cout << std::sqrt(boost::ref(y)) << std::endl;

	std::vector<int> v(10, 2);
	BOOST_AUTO(rwv, boost::cref(v));
	assert(is_reference_wrapper<BOOST_TYPEOF(rwv)>::value);
	assert(!is_reference_wrapper < BOOST_TYPEOF(v)>::value);

	std::string strr;
	BOOST_AUTO(rwstr, boost::ref(strr));
	std::cout << typeid(unwrap_reference<BOOST_TYPEOF(rwstr)>::type).name() << std::endl;
	std::cout << typeid(unwrap_reference<BOOST_TYPEOF(strr)>::type).name() << std::endl;
}