#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace boost::uuids;
using namespace std;


int main()
{
	string_generator sgen;
	uuid u1 = sgen("0123456789abcdef0123456789abcdef");
	cout << u1 << endl;
	uuid u2 = sgen("01234567-89ab-cdef-0123-456789abcdef");
	cout << u2 << endl;
	uuid u3 = sgen(L"{01234567-89ab-cdef-0123-456789abcdef}");
	cout << u3 << endl;

	uuid www_xxx_com = string_generator()("{0123456789abcdef0123456789abcdef}");
	name_generator ngen(www_xxx_com);

	uuid u4 = ngen("dengxin");
	assert(!u4.is_nil() && u4.version() == uuid::version_name_based_sha1);
	cout << u4 << endl;
	uuid u5 = ngen("xindeng");
	cout << u5 << endl;

	random_generator rgen;
	uuid u6 = rgen();
	assert(u6.version() == uuid::version_random_number_based);
	cout << u6 << endl;
}