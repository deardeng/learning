#define BOOST_THREAD_VERSION 4

#include <algorithm>
#include <fstream>
#include <iterator>

void set_not_first_run();
bool is_first_run();

// ��ʱ��ִ�еĺ���
void fill_file_with_data(char fill_char, std::size_t size, const char* filename)
{
	std::ofstream ofs(filename);
	std::fill_n(std::ostreambuf_iterator<char>(ofs), size, fill_char);
	set_not_first_run();
}

void example_without_threads()
{
	// ...
	// �ڻ����û�������߳�ĳ��
	if (is_first_run())
	{
		// �⽫ִ�кܳ�һ��ʱ�䣬�ڼ��û����潫����
		fill_file_with_data(0, 8 * 1024 * 1024, "save_file.txt");
	}
}

#include <boost/thread.hpp>
#include <string>
void example_with_threads()
{
	// ...
	// �ڻ����û�������߳�ĳ��
	if (is_first_run())
	{
		boost::thread(boost::bind(
			&fill_file_with_data,
			'*',
			8 * 1024 * 1024,
			"save_file.txt"
			)).detach();
	}
}

void example_with_joining_threads()
{
	// ...
	// �ڻ����û�������߳�ĳ��
	if (is_first_run())
	{
		boost::thread t(boost::bind(
			&fill_file_with_data,
			'*',
			8 * 1024 * 1024,
			"save_file.txt"
			));

		// ��һЩ����
		// ...
		// �ȴ��߳����
		t.join();
	}
}

int main()
{
	example_with_threads();
	example_with_joining_threads();

	system("pause");
	return 0;
}

#include <boost/thread/scoped_thread.hpp>
void some_func();
void example_with_raii()
{
	boost::scoped_thread<boost::join_if_joinable> t(
		(boost::thread(&some_func))
		);

	// 't'�����˳�������ʱ����
}

static bool g_is_first_run = true;
void set_not_first_run()
{
	g_is_first_run = false;
}

bool is_first_run()
{
	return g_is_first_run;
}

void some_func() {}