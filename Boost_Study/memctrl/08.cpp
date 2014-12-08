#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <boost/smart_ptr.hpp>
using namespace boost;

class abstract
{
public:
	virtual void f() = 0;
	virtual void g() = 0;
protected:
	virtual ~abstract(){}
};

class impl:public abstract
{
public:
	virtual void f()
	{
		std::cout << "class impl f" << std::endl;
	}
	virtual void g()
	{
		std::cout << "class impl g" << std::endl;
	}
};

shared_ptr<abstract> create()
{
	return shared_ptr<abstract>(new impl);
}

int main()
{
	shared_ptr<abstract> p = create();
	p->f();
	p->g();
	std::cout << p.use_count() << std::endl;
	impl *q = (impl*)(p.get());
	delete q;
}