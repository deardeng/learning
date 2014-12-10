#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/assign.hpp>
using namespace boost::assign;
using namespace std;
int main()
{
	vector<int> v;
	v += 1,2,3,4,5, 6*6;

	set<string> s;
	s += "cpp", "java", "c#", "python";

	map<int, string> m;
	m += make_pair(1, "one"),make_pair(2, "two");

	vector<int> v1;
	push_back(v1) (1) (2) (3) (4) (5);

	list<string> l;
	push_front(l) ("cpp") ("java") ("c#") ("python");

	set<double> s1;
	insert(s1) (3.14) (0.618) (1.732);

	map<int, string> m1;
	insert(m1) (1, "one") (2, "two");

	vector<int> v2;
	push_back(v2), 1, 2, 3, 4, 5;
	push_back(v2), (6), 7, 64/8, (9), 10;
	
	deque<string> d;
	push_front(d)() = "cpp" , "java", "c#", "python";
	assert(d.size() == 5);
}