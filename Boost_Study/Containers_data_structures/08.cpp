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
	int n;
	cin >> n;
	dynamic_bitset<> db(n);

	db.set();
	for(dynamic_bitset<>::size_type i = db.find_next(1); i != dynamic_bitset<>::npos; i = db.find_next(i))
	{
		for(dynamic_bitset<>::size_type j = db.find_next(i); j != dynamic_bitset<>::npos; j = db.find_next(j))
		{
			cout << "i= " << i << " j= " << j << endl;
			if(j % i == 0)
			{
				cout << "*****" << " j= " << j << endl;
				db[j] = 0;
			}
		}
	}

	for(dynamic_bitset<>::size_type i = db.find_next(2); i != dynamic_bitset<>::npos; i = db.find_next(i))
	{
		cout << i << ", ";
	}
}