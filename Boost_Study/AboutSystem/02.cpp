#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
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
#include <boost/cstdint.hpp>
#include <limits>
//Here Windows bug? Linux is OK
#define BOOST_NO_STD_LOCALE 
//Here Windows bug? Linux is OK
#include <boost/io/ios_state.hpp>
#include <fstream>

#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>

using namespace boost;
using namespace boost::io;

template<int N = 2>
class new_progress_timer : public boost::timer
{
public:
	new_progress_timer(std::ostream& os = std::cout)
		:m_os(os)
	{
		BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
	}
	~new_progress_timer()
	{
		try
		{
			boost::io::ios_all_saver ios(m_os);
			m_os.setf(std::istream::fixed, std::istream::floatfield);
			m_os.precision(N);

			m_os << elapsed() << " s\n" << std::endl;
		}
		catch (...){}

	}
private:
	std::ostream& m_os;
};

template<> class new_progress_timer<2> :public boost::progress_timer{};

int main()
{
	new_progress_timer<> t;
}