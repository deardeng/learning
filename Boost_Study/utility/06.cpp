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
	vector<int> v = list_of(1) (2) (3) (4) (5);
	deque<string> d = (list_of("power") ("bomb"), "phazon", "suit");

	set<int> s = (list_of(10), 20, 30, 40, 50);

	map<int, string> m = list_of(make_pair(1, "one")) (make_pair(2, "two"));

	map<int, int> m1 = map_list_of(1, 2) (3, 4) (5, 6);
	map<int, string> m2 = map_list_of(1, "one") (2, "two");

	vector<int> v1 = list_of(1).repeat(3,2) (3) (4) (5);

	multiset<int> ms;
	insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;

	deque<int> d1;
	push_front(d1).range(v1.begin(), v1.begin()+5);
}