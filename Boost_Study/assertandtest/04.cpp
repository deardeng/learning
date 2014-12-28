#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <boost/format.hpp>
#include <boost/test/minimal.hpp>


int test_main(int argc, char* argv[])
{
	using namespace boost;
	format fmt("%d-%d");

	BOOST_CHECK(fmt.size() != 0);
	fmt % 12 % 34;
	BOOST_REQUIRE(fmt.str() == "12-34");

	BOOST_ERROR("��ʾһ��������Ϣ");
	fmt.clear();
	fmt % 12;
	try
	{
		std::cout << fmt;
	}
	catch(...)
	{
		BOOST_FAIL("�������󣬲�����ֹ");
	}
	return 0;
}