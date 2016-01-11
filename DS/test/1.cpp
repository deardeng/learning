#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <string>
using namespace std;

int main()
{
	map<string, int>   my_Map1;
	my_Map1["a"] = 1;
	my_Map1["b"] = 2;
	my_Map1["c"] = 3;


	map<string, int>   my_Map2;
	my_Map2["e"] = 4;
	my_Map2["f"] = 5;
	my_Map2["g"] = 6;


	list<map<string, int> > ltest;
	ltest.push_back(my_Map1);
	ltest.push_back(my_Map2);

	for (list<map<string, int> >::iterator i = ltest.begin(); i != ltest.end(); ++i)
	{
		for (map<string, int>::iterator j = i->begin(); j != i->end(); ++j)
			cout << j->second << ';' << /*(j->first).c_str()*/ /*const_cast<string&>*/(j->first) << endl;
		cout << endl;
	}

}