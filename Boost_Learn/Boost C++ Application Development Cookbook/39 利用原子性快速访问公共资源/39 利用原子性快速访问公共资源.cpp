#include <cassert>
#include <cstddef>

#include <boost/thread/thread.hpp>
#include <boost/atomic.hpp>

boost::atomic<int> shared_i(0);

void do_inc()
{
	for (std::size_t i = 0; i < 30000; ++i)
	{
		// ��һЩ����
		// ...
		const int i_snapshot = ++shared_i;

		// ��һЩ��i_snapshot�йصĹ���
		// ...
		(void)i_snapshot;
	}
}

void do_dec()
{
	for (std::size_t i = 0; i < 30000; ++i)
	{
		// ��һЩ����
		// ...
		const int i_snapshot = --shared_i;

		// ��һЩ��i_snapshot�йصĹ���
		// ...
	}
}

int main()
{
	boost::thread t1(&do_inc);
	boost::thread t2(&do_dec);

	t1.join();
	t2.join();

	assert(shared_i == 0);
	std::cout << "shared_i == " << shared_i << std::endl;

	assert(shared_i.is_lock_free());

	system("pause");
	return 0;
}

#include <boost/static_assert.hpp>
BOOST_STATIC_ASSERT(BOOST_ATOMIC_INT_LOCK_FREE == 2);