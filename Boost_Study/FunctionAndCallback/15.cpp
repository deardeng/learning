#include <iostream>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <boost/rational.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::assign;

class demo_class
{
private:
	typedef function<void(int)> func_t;
	func_t func;
	int n;
public:
	demo_class(int i) : n(i){}
	template<typename CallBack>
	void accept(CallBack f)
	{
		func = f;
	}
	void run()
	{
		func(n);
	}
};

void call_back_func(int i)
{
	std::cout << "call back func: ";
	std::cout << i * 2 << std::endl;
}

int main()
{
	demo_class dc(10);
	dc.accept(call_back_func);
	dc.run();
}