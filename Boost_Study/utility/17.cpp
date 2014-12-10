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
class my_smart_array:
	public indexable<my_smart_array<T>, int, T& >
{
	T *p;
public:
	typedef my_smart_array<T> this_type;
	typedef T* iter_type;
	my_smart_array(T *x):p(x){}
	~my_smart_array(){delete[] p;}
	T& operator*() const
	{
		return *p;
	}
	friend iter_type operator+(const this_type& a, int n)
	{
		return a.p + n;
	}
};
int main()
{
	my_smart_array<double> ma(new double[10]);
	*(ma + 0) = 3.0;
	ma[0] = 1.0;
	*(ma + 1) = 2.0;
	cout << ma[0] << ' ' <<  ma[1] << endl;
}