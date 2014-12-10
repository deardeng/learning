#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <boost/assign.hpp>
#include <boost/operators.hpp>
#include <boost/typeof/typeof.hpp>
using namespace boost;
using namespace std;

template<typename T>
class my_smart_ptr : public dereferenceable<my_smart_ptr<T>, T* >
{
	T *p;
public:
	my_smart_ptr(T *x):p(x){}
	~my_smart_ptr(){delete p;}
	T& operator*() const
	{
		return *p;
	}
};
int main()
{
	my_smart_ptr<string > p(new string("123"));
	assert(p->size() == 3);
}