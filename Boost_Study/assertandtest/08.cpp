#include <boost/smart_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
{
	boost::shared_ptr<int> p(new int(10));
	BOOST_TEST(*p == 10);
	BOOST_TEST(p.use_count(), 1);
	BOOST_ERROR("error accored!!");
}