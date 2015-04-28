#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <set>
using namespace boost;
using namespace boost::assign;

class big_class
{
private:
	int x;
public:
	big_class() :x(0){}
	void print()
	{
		std::cout << "big_class " << ++x << std::endl;
	}

};

template<typename T>
void print(T a)
{
	for (int i = 0; i < 2; ++i)
		unwrap_ref(a).print();
}

int main()
{
	big_class c;
	BOOST_AUTO(rw, boost::ref(c));
	c.print();


	print(c);
	print(rw);
	print(c);
	c.print();
}