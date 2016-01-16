#include<cstring>
#include<boost/thread.hpp>
#include<boost/bind.hpp>

void do_process(const char* data, std::size_t size);

void do_process_in_backgroud(const char* data, std::size_t size)
{
	// ������Ҫ�������ݣ���Ϊ���ǲ�֪����ʲôʱ��ᱻ�������ͷ�
	char* data_cpy = new char[size];
	std::memcpy(data_cpy, data, size);

	// ����ִ���߳�����������
	boost::thread(boost::bind(&do_process, data_cpy, size)).detach();

	// ���ǲ���delete[] data_cpy, ��Ϊdo_process1 �� do_process2 ������Ȼ��ʹ����
}

#include <boost/shared_array.hpp>
void do_process_shared_array(const boost::shared_array<char>& data, std::size_t size)
{
	do_process(data.get(), size);
}

 // ��һ�����������boost�Ĵ�ͳ��������boost 1.53ǰ���ڶ�����������Ĺ���û����shared_ptr��ʵ�֡�
void do_process_in_background_v1(const char* data, std::size_t size)
{
	// ������Ҫ�������ݣ���Ϊ���ǲ�֪����ʲôʱ��ᱻ�������ͷ�
	boost::shared_array<char> data_cpy(new char[size]);
	std::memcpy(data_cpy.get(), data, size);
	// ����ִ���߳�����������
	boost::thread(boost::bind(&do_process_shared_array, data_cpy, size)).detach();

	// ����Ҫ��data_cpy����delete[], ��Ϊ�����ü���Ϊ��ʱ��data_cpy�������������ͷ�����
}

#include<boost/shared_ptr.hpp>
#include<boost/make_shared.hpp>

void do_process_shared_ptr(const boost::shared_ptr<char[]>& data, std::size_t size)
{
	do_process(data.get(), size);
}

//�ڶ����������������һ������ʹ�ý��ٵ�new���ã�������ֻ������boost 1.53�͸��߰汾��

void do_process_in_background_v2(const char* data, std::size_t size)
{
	// ִ���ٶȱȵ�һ�����������
	boost::shared_ptr<char[]> data_cpy = boost::make_shared<char[]>(size);
	std::memcpy(data_cpy.get(), data, size);

	// ����ִ���߳�����������
	boost::thread(boost::bind(&do_process_shared_ptr, data_cpy, size)).detach();

	// �����ü���Ϊ��ʱ�� data_cpy�������������ͷ�����
}

void do_process_shared_ptr2(const boost::shared_ptr<char>& data, std::size_t size)
{
	do_process(data.get(), size);
}

//��������������ǿ���ֲ����õġ����������ھɰ汾��Boost��C+++11STL��shared_ptr<>��ֻ�ǲ�Ҫ���ǽ�boost::checked_array_deleter<T>()��Ϊstd::default_delete<T[]>() ����

void do_process_in_background_v3(const char* data, std::size_t size)
{
	// ִ���ٶ����һ�����������ͬ
	boost::shared_ptr<char> data_cpy(new char[size], boost::checked_array_deleter<char>());
	std::memcpy(data_cpy.get(), data, size);

	// ����ִ���߳�����������
	boost::thread(boost::bind(&do_process_shared_ptr2, data_cpy, size)).detach();

	// �����ü���Ϊ��ʱ�� data_cpy�������������ͷ�����
}

#include<boost/chrono/duration.hpp>

int main()
{
	// do_process_in_background(); // Will cause a memory leak
	char ch[] = "Hello deardeng.";
	do_process_in_background_v1(ch, sizeof(ch));
	do_process_in_background_v2(ch, sizeof(ch));
	do_process_in_background_v3(ch, sizeof(ch));

	// Give all the threads a chance to finish
	// Note: It is an awfull design, but it is OK
	// for example
	boost::this_thread::sleep_for(boost::chrono::seconds(2));
	
	system("pause");
	return 0;
}

void do_process(const char* data, std::size_t size)
{
	assert(size);
	assert(data);
}