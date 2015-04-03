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
	dynamic_bitset<> db(10, BOOST_BINARY(1010101));
	cout << db.to_ulong() << endl;

	db.append(10);
	cout << db.to_ulong() << endl;
	cout << "----" << std::numeric_limits<unsigned long>::max() << "----" << endl;
	db.push_back(1);
	//cout << db.to_ulong() << endl;

	string str;
	to_string(db, str);
	cout << str << endl;

}