#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/utility/binary.hpp>
#include <boost/typeof/typeof.hpp>
#include <hash_set>
#include <boost/assign.hpp>
using namespace std;
using namespace boost;

int main()
{
	using namespace boost::assign;

	unordered_map<int, string> um = map_list_of(1, "one") (2, "two") (3, "three");
	
	um.insert(make_pair(10, "ten"));
	cout << um[10] << endl;
	um[11] = "eleven";
	um[15] = "fifteen";

	BOOST_AUTO(p, um.begin());
	for(p; p != um.end(); ++p)
	{
		cout << p->first << "-" << p->second << ",";
	}
	cout << endl;

	um.erase(11);
	cout << um.size() << endl;

	//hash_map<int, string> hm = map_list_of(4, "four") (5,"five") (6, "six");

	//BOOST_AUTO(q, hm.begin());
	//for(q; q != hm.end(); ++q)
	//{
	//	cout << q->first << "-" << q->second << ",";
	//}
	//cout << endl;
}