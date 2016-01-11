#define _SCL_SECURE_NO_WARNINGS
#include "boost/utility/result_of.hpp"
#include "boost/typeof/typeof.hpp"
#include "boost/assign.hpp"
#include "boost/ref.hpp"
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/signals2.hpp"
#include "iostream"
using namespace std;


void slots1()
{
	cout << "slots1 call" << endl;
}

void slots2()
{
	cout << "slots2 call" << endl;
}


struct Hello
{
	void operator()() const
	{
		std::cout << "Hello";
	}
};

int main(int argc, char* argv[])
{
	boost::signals2::signal<void()> sig;
	sig.connect(&slots1);
	sig.connect(&slots2);

	sig();

	boost::signals2::signal<void()> sig1;

	sig1.connect(Hello());
	sig1();


	return 0;
}
