#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>
#include <boost/utility/binary.hpp>
using namespace std;
using namespace boost;

int main()
{
	dynamic_bitset<> db1;
	dynamic_bitset<> db2(10);
	dynamic_bitset<> db3(0x10, BOOST_BINARY(10101));
	dynamic_bitset<> db4(string("0100"));
	dynamic_bitset<> db5(db3);

	dynamic_bitset<> db6;
	db6 = db4;

	cout << hex << db3.to_ulong() << endl;
	cout << db4[0] << db4[1] << db4[2] << endl;
	assert(dynamic_bitset<>(32).num_blocks() == 1);
	assert(dynamic_bitset<>(64).num_blocks() == 2);
	dynamic_bitset<> db7(5, BOOST_BINARY(01001));
	db7.push_back(true);
	assert(db7.to_ulong() == BOOST_BINARY_UL(101001));

	db7.append(BOOST_BINARY(101));
	assert(db7.size() == sizeof(unsigned long)*8 + 6);
	cout << db7 << endl;
}