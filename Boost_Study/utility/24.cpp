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
	uuid u10;
	assert(uuid::static_size() == 16);
	assert(u10.size() == 16);

	vector<unsigned char> v(16, 7);
	std::copy(v.begin(), v.end(), u10.begin());
	assert(u10.data[0] == u10.data[1] && u10.data[15] == 7);

	cout << u10 << endl;
	std::fill_n(u10.data + 10, 6, 8);
	cout << u10 << endl;

	uuid u;
	std::fill_n(u.begin(),u.size(), 0xab);
	assert(!u.is_nil());
	assert(u.variant() == u.variant_rfc_4122);
	assert(u.version() == u.version_unknown);
	cout << u << endl;

	std::memset(u.data, 0, 16);
	assert(u.is_nil());

	uuid u1, u2;
	std::fill_n(u1.begin(), u1.size(), 0xab);
	std::fill_n(u2.begin(), u2.size(), 0x10);
	assert(u1 != u2 && u1 > u2);

	u2.data[0] = 0xff;
	assert(u1 < u2);

	std::memset(u1.data, 0, 16);
	std::memset(u2.data, 0, 16);
	assert(u1 == u2);

	uuid u3 = nil_generator()();
	assert(u.is_nil());
	
	uuid u4;
	u4 = nil_uuid();
	assert(u.is_nil());
}