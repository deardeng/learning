#define BOOST_TEST_INCLUDE
#include <boost/test/unit_test.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/mpl/list.hpp>
using namespace boost;

BOOST_AUTO_TEST_SUITE(s_lexical_cast)

typedef mpl::list<short, int, long> types;
BOOST_AUTO_TEST_CASE_TEMPLATE(t_lexical_cast, T, types)
{
	T n(20);
	BOOST_CHECK_EQUAL(lexical_cast<string>(n), "20");
}

BOOST_AUTO_TEST_SUITE_END()