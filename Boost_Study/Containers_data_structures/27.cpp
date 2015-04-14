#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <boost/variant.hpp>
#include <boost/mpl/vector.hpp>
using namespace boost;

typedef variant<int, double, std::vector<int> > var_t;

struct var_print : public static_visitor < >
{
	template<typename T>
	void operator()(T &i) const
	{
		//i *= 2;
		std::cout << i << std::endl;
	}
	template<>
	void operator() < std::vector<int> > (std::vector<int> &v) const
	{
		v.reserve(v.size() * 2);
		copy(v.begin(), v.end(), back_inserter(v));
		//for (int i = 0; i < v.size(); ++i)
		//{
		//	std::cout << v[i] << ",";
		//}
		//} 
		for (auto& x : v)
		{
			std::cout << x << ",";
		}
		std::cout << std::endl;
	}
};

struct is_var_equal : public static_visitor < bool >
{
	template<typename T, typename U>
	bool operator()(const T &t, const U &u) const
	{
		if (typeid(T) != typeid(U))
			return false;
		//return t == u;
		return true;
	}
};

template<BOOST_VARIANT_ENUM_PARAMS(typename T) >
void op_var(variant<BOOST_VARIANT_ENUM_PARAMS(T)>& v)
{
	std::cout << v << std::endl;
}

typedef boost::mpl::vector<int, double, std::vector<std::string> > var_types;

int main()
{
	var_t v1(1);
	var_t v2(2.3);
	apply_visitor(is_var_equal(), v1, v2);
	apply_visitor(is_var_equal()) (v1, v2);
	make_variant_over<var_types>::type v;
	v = 2.13;
}