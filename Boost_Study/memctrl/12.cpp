#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/enable_shared_from_this.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost;

class self_shared : public enable_shared_from_this<self_shared>
{
public:
	self_shared(int n):x(n){}
	int x;
	void print()
	{
		std::cout << "self_shared:" << x << std::endl;
	}
};

int main()
{
	shared_ptr<self_shared> sp = make_shared<self_shared>(314);
	sp->print();
	shared_ptr<self_shared> p = sp->shared_from_this();
	p->x = 1000;
	p->print();
	sp->x = 1200;
	p->print();

	self_shared ss(321);
	shared_ptr<self_shared> ps = ss.shared_from_this();
}