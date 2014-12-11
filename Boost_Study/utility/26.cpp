#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/lexical_cast.hpp>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace boost;
using namespace boost::uuids;
using namespace std;

class uuid_t : public uuid
{
private:
	static random_generator rgen;
	static string_generator sgen;
public:
	uuid_t():uuid(rgen()){}
	uuid_t(int):uuid(nil_uuid()){}
	uuid_t(const char* str):uuid(sgen(str)){}
	uuid_t(const uuid& u, const char* str):
		uuid(name_generator(u)(str)){}
	explicit uuid_t(const uuid& u):uuid(u){}
	operator uuid()
	{
		return static_cast<uuid&>(*this);
	}
	operator uuid() const
	{
		return static_cast<const uuid&>(*this);
	}
};

random_generator uuid_t::rgen;
string_generator uuid_t::sgen;
int main()
{
	uuid_t u0 = 0;
	assert(u0.is_nil());

	uuid_t u1, u2;
	cout << u1 << endl;
	cout << u2 << endl;

	uuid_t u3("{01234567-89ab-cdef-0123-456789abcdef}");
	cout << u3 << endl;
	cout << uuid_t(u3, "test name gen") << endl;


	stringstream ss;
	ss << u3;
	string str;
	ss >> str;
	cout << str << endl;
	cout << "===========================================" << endl;
	uuid u4 = lexical_cast<uuid>("92eee8af-f83a-4da1-a499-63bbeb0f81fd");
	string str1 = lexical_cast<string>(u4);
	cout << str1 << endl;
}