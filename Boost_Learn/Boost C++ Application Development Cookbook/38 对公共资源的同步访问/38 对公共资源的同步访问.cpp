#include <cassert>
#include <cstddef>

// ������37�а�����<boost/thread.hpp>, ��������Boost.Thread�е�������
#include <boost/thread/thread.hpp>

namespace without_sync
{
	int shared_i = 0;

	void do_inc()
	{
		for (std::size_t i = 0; i < 30000; ++i)
		{
			// ��һЩ����
			// ...
			int i_snapshot = ++shared_i;

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
			int i_snapshot = --shared_i;

			// ��һЩ��i_snapshot�йصĹ���
			// ...
			(void)i_snapshot;
		}
	}

	void run()
	{
		boost::thread t1(&do_inc);
		boost::thread t2(&do_dec);

		t1.join();
		t2.join();

		//assert(shared_i == 0); // Oops!
		std::cout << "shared_i == " << shared_i;
	}
} // namespace without_sync

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

namespace with_sync
{
	int shared_i = 0;
	boost::mutex i_mutex;

	void do_inc()
	{
		for (std::size_t i = 0; i < 30000; ++i)
		{
			// ��һЩ����
			// ...
			int i_snapshot;
			{// �ٽ�����ʼ
				boost::lock_guard<boost::mutex> lock(i_mutex);
				i_snapshot = ++shared_i;
			}// �ٽ�������

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
			int i_snapshot;
			{// �ٽ�����ʼ
				boost::lock_guard<boost::mutex> lock(i_mutex);
				i_snapshot = --shared_i;
			}// �ٽ�������

			 // ��һЩ��i_snapshot�йصĹ���
			 // ...
			(void)i_snapshot;
		}
	}
	void run()
	{
		boost::thread t1(&do_inc);
		boost::thread t2(&do_dec);

		t1.join();
		t2.join();

		assert(shared_i == 0);
		std::cout << "shared_i == " << shared_i;
	}
} // namespace with_sync

#include <boost/thread/recursive_mutex.hpp>

int main()
{
	without_sync::run();
	std::cout << '\n';
	with_sync::run();
	std::cout << '\n';

	system("pause");
	return 0;
}