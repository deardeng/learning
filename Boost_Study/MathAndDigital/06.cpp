#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <boost/multi_array.hpp>
#include <cstddef>
#include <stdexcept>
#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/unordered_set.hpp>
#include <boost/integer_traits.hpp>
#include <boost/cstdint.hpp>
#include <limits>
#include <boost/integer.hpp>
#include <boost/format.hpp>
#include <boost/rational.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/operators.hpp>
#include <boost/algorithm/minmax.hpp>
using namespace boost;

class iint : totally_ordered < iint >
{
public:
	iint(int n = 0) :is_positive(n > 0 ? true : (n < 0 ? false : indeterminate))
	{
		static format fmt("%d");
		intstr = (fmt % (is_positive || indeterminate(is_positive) ? n : -n)).str();

		std::reverse(intstr.begin(), intstr.end());
		std::transform(intstr.begin(), intstr.end(), intstr.begin(), std::bind2nd(std::minus<char>(), 0x30));
	}

	iint& operator=(const iint& r)
	{
		is_positive = r.is_positive;
		intstr = r.intstr;
		return *this;
	}

	std::string to_string() const
	{
		std::string tmp(intstr);
		if (!is_positive)
		{
			tmp += "-";
		}
		std::reverse(tmp.begin(), tmp.end());
		std::transform(tmp.begin() + (is_positive ? 0 : 1), tmp.end(),
			tmp.begin() + (is_positive ? 0 : 1),
			std::bind2nd(std::plus<char>(), 0x30));
		return tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, const iint& x)
	{
		os << x.to_string();
		return os;
	}

	friend bool operator==(const iint& l, const iint& r)
	{
		return (indeterminate(l.is_positive) && indeterminate(r.is_positive)) || (l.is_positive == r.is_positive && l.intstr == r.intstr);
	}

	friend bool operator<(const iint& l, const iint& r)
	{
		if (indeterminate(l.is_positive) && indeterminate(r.is_positive)
			|| l.is_positive && indeterminate(r.is_positive))
		{
			return false;
		}
		return (indeterminate(l.is_positive) && r.is_positive) ||
			bool(l.is_positive) < bool(r.is_positive) ||
			l.intstr.size() < r.intstr.size() ||
			l.intstr < r.intstr;
	}

	iint& operator+()
	{
		return *this;
	}

	bool operator!()
	{
		return !indeterminate(is_positive);
	}

	iint& operator+=(const iint& r)
	{
		BOOST_AUTO(x, boost::minmax(intstr.size(), r.intstr.size()));

		intstr.append(x.get<1>() + 1 - intstr.size(), 0);

		for (size_t i = 0; i < x.get<1>(); ++i)
		{
			if (i < r.intstr.size())
			{
				intstr[i] += r.intstr[i];
			}
			if (intstr[i] > 9)
			{
				intstr[i] -= 10;
				++intstr[i + 1];
			}
		}
		return *this;
	}

	iint& operator++()
	{
		*this += 1;
		return *this;
	}

private:
	tribool is_positive;
	std::string intstr;
};



int main()
{
	iint a(56787);
	std::cout << a << std::endl;
	iint b(123);
	std::cout << b << std::endl;
	std::cout << "*****************" << std::endl;
	std::cout << (b += a) << std::endl;
	return 0;
}