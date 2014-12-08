#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
using namespace std;
using namespace boost;

struct posix_file
{
	posix_file(const char* file_name)
	{
		cout << "open file:" << file_name << endl;
	}
	~posix_file()
	{
		cout << "close file" << endl;
	}

};

int main()
{
	scoped_ptr<string> sp(new string("text"));
	cout << *sp << endl;
	cout << sp->size() << endl;


	scoped_ptr<int> p(new int);
	if(p)
	{
		*p = 100;
		cout << *p << endl;
	}
	p.reset();
	assert(p == 0);
	if(!p)
	{
		cout << "scoped_ptr == null" << endl;
		scoped_ptr<posix_file> fp(new posix_file("/tmp/a.txt"));
	}
}