#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/array.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace std;
int main()
{
	int a[10] = {0};
	array<int, 10> ar = {0};
	assert(std::equal(ar.begin(), ar.end(), a));
	array<string, 3>ar2 = {"racer"};
	assert(ar2.at(1).empty());

	using namespace boost::assign;
	array<int, 3> arr(list_of(2) (4) (6));
	for(int i=0; i<arr.size(); ++i)
	{
		cout << arr[i] << ",";
	}
}