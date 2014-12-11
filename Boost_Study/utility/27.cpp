#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/lexical_cast.hpp>
#include <sstream>

#include <boost/uuid/sha1.hpp>
using namespace boost::uuids::detail;

using namespace std;


int main()
{
	sha1 sha;
	char *szMsg = "a short message";
	sha.process_byte(0x10);
	sha.process_bytes(szMsg, strlen(szMsg));
	sha.process_block(szMsg, szMsg+strlen(szMsg));

	unsigned int digest[5];
	sha.get_digest(digest);
	for(int i=0; i<5; ++i)
	{
		cout << hex << digest[i];
	}
}