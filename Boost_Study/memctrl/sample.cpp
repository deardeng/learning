#include "sample.h"

class sample::impl
{
public:
	void print()
	{
		std::cout << "impl print" << std::endl;
	}
};

sample::sample():p(new impl)
{
}


void sample::print()
{
	p->print();
}
