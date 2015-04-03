#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>
#include <boost/utility/binary.hpp>
#include <boost/typeof/typeof.hpp>
using namespace std;
using namespace boost;

int main()
{
	dynamic_bitset<> db1(4, BOOST_BINARY(1010));

	db1[0] &= 1;
	db1[1] ^= 1;
	cout << db1 << endl;

	dynamic_bitset<> db2(4, BOOST_BINARY(0101));
	assert(db1 > db2);

	cout << (db1 ^ db2) << endl;
	cout << (db1 | db2) << endl;

	dynamic_bitset<> db3(4, BOOST_BINARY(0101));
	assert(db3.test(0) && !db3.test(1));
	assert(db3.any() && !db3.none());
	assert(db3.count() == 2);

	dynamic_bitset<> db4(4, BOOST_BINARY(0101));
	db4.flip();
	assert(db4.to_ulong() == BOOST_BINARY(1010));

	db4.set();
	assert(!db4.none());

	db4.reset();
	assert(!db4.any());

	db4.set(1, 1);
	assert(db4.count() == 1);

	dynamic_bitset<> db5(5, BOOST_BINARY(00101));
	BOOST_AUTO(pos, db5.find_first());
	assert(pos == 0);
	pos = db5.find_next(pos);
	assert(pos == 2);
}