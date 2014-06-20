#include <iostream>
using namespace std;

class Object
{
public:
	Object(int num) : num_(num)
	{
		cout<<"Object "<<num_<<" ..."<<endl;
	}
	~Object()
	{
		cout<<"~Object "<<num_<<" ..."<<endl;
	}
private:
	int num_;
};

class Container
{
public:
	Container(int obj1=0, int obj2=0) : obj2_(obj2), obj1_(obj1)
	{
		cout<<"Container ..."<<endl;
	}
	~Container()
	{
		cout<<"~Container ..."<<endl;
	}

private:
	Object obj1_;
	Object obj2_;
};

int main(void)
{
	Container c(10,20);
	return 0;
}