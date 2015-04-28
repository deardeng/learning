#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <cstddef>
#include <stdexcept>
#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/cstdint.hpp>
#include <limits>
//Here Windows bug? Linux is OK
#define BOOST_NO_STD_LOCALE 
//Here Windows bug? Linux is OK
#include <boost/io/ios_state.hpp>
#include <fstream>
using namespace boost;
using namespace boost::io;

void logging(const char* msg)
{
	std::cout << msg << std::endl;
}

int main()
{
	std::string filename("test.txt");
	std::cout << "log start" << std::endl;

	if (!filename.empty())
	{
		ios_all_saver ifs(std::cout);
		std::ofstream fs(filename.c_str());
		std::cout.rdbuf(fs.rdbuf());
		logging("fatal msg");
	}
	std::cout << "log finish" << std::endl;
}