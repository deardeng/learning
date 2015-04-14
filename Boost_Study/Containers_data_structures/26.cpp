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
	void operator()< std::vector<int> > (std::vector<int> &v) const
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

int main()
{
	var_t v(1);
	var_print vp;
	apply_visitor(vp, v);
	
	v = 3.14;
	apply_visitor(vp, v);

	using namespace boost::assign;
	v = std::vector<int>(list_of(1) (2));
	apply_visitor(vp, v);

	var_t v1(1);
	//var_print vp2;
	BOOST_AUTO(vp1, apply_visitor(var_print()));
	vp1(v1);
	std::cout << "..........................." << std::endl;
	auto vp2 = apply_visitor(vp);
	vp2(v);
	std::vector<int> a(list_of(1) (2));

	typedef std::vector <
		boost::variant<int, std::string, double> > vec_type;
	vec_type vec;	
	vec.push_back(12);
	vec.push_back(1.12);
	for_each(vec.begin(), vec.end(), apply_visitor(var_print()));
}