#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <boost/assign.hpp>
#include <hash_map>
using namespace boost::assign;
using namespace std;
int main()
{
	hash_map<string, int> hm = map_list_of("one", 1) ("two", 2);
	vector< vector<int> > v = list_of(list_of(1) (2)) (list_of(3) (4));
	v += list_of(5) (6) ,list_of(7) (8);
	int a = 1, b = 2, c = 3;
	vector<int> v1 = ref_list_of<3>(a) (b) (c);
	assert(v1.size() == 3);
}