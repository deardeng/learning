#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
using namespace std;
using namespace boost;


int main()
{
	scoped_array<int> sa(new int[100]);
	sa[0] = 10;

	int *arr = new int[100];
	scoped_array<int> saa(arr);
	fill_n(&sa[0], 100, 5);
	saa[10] = sa[20] + sa[30];

}