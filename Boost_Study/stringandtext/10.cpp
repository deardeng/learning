#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace std;

int main()
{
	string str = "Samus beat the monster.\n";
	cout << replace_first_copy(str, "Samus", "samus");

	replace_last(str, "beat", "kill");
	cout << str;

	replace_tail(str, str.end() - find_last(str, "monster").begin() , "ridley.\n");
	cout << str;

	cout << ierase_all_copy(str, "samus");
	cout << replace_nth_copy(str, "l", 1, "L");
	cout << erase_tail_copy(str, 8);

}