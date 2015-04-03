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

template<typename T>
void hash_func()
{
	using namespace boost::assign;
	T s = (list_of(1), 2, 3, 4, 5);
	for(T::iterator p = s.begin(); p != s.end(); ++p)
	{
		cout << *p << " ";
	}
	cout << endl;
	cout << s.size() << endl;

	s.clear();
	cout << s.empty() << endl;

	s.insert(8);
	s.insert(45);
	cout << s.size() << endl;
	cout << *s.find(8) << endl;

	s.erase(45);
}

int main()
{
	hash_func<hash_set<int> >();
	hash_func<unordered_set<int> >();
}