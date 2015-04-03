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
		dynamic_bitset<> db1(5, BOOST_BINARY(10101));
		dynamic_bitset<> db2(5, BOOST_BINARY(10010));

		cout << (db1 | db2) << endl;
		cout << (db1 & db2) << endl;
		cout << (db1 - db2) << endl;

		dynamic_bitset<> db4(db2);
		assert(db4.is_subset_of(db2));
		assert(!db4.is_proper_subset_of(db2));
}