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

class call_back_obj
{
private:
	int x;
public:
	call_back_obj(int i) : x(i){}
	void operator()(int i)
	{
		std::cout << "call back obj : ";
		std::cout << i* x++ << std::endl;
	}
};

int main()
{
	demo_class dc(10);
	call_back_obj cbo(2);
	dc.accept(ref(cbo));
	dc.run();
	dc.run();

}