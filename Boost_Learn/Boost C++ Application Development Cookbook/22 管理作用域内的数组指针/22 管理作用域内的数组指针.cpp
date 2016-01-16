
void may_throw1(const char* buffer);
void may_throw2(const char* buffer);

void foo()
{
	//������ջ�Ϸ���10MB���ڴ棬�����ڶ��Ϸ�����
	char* buffer = new char[1024 * 1024 * 10];
	//������һЩ���ܻ��׳��쳣�Ĵ���
	may_throw1(buffer);
	may_throw2(buffer);

	delete[] buffer;
}

#include <boost/scoped_array.hpp>

void foo_fixed()
{
	//�ڶ��Ϸ�����
	boost::scoped_array<char> buffer(new char[1024 * 1024 * 10]);
	//������һЩ�����׳��쳣�Ĵ��룬���������쳣���ᵼ���ڴ�й©
	may_throw1(buffer.get());
	may_throw2(buffer.get());

	// 'buffer'�������������������delete[]
}

#include<stdexcept>
#include<assert.h>

int main()
{
	//foo(); // Leaks memory

	try
	{
		foo_fixed();
	}
	catch (...)
	{

	}
	system("pause");
	return 0;
}

void may_throw1(const char* /*buffer*/)
{
	// Do nothing
}

void may_throw2(const char* /*buffer*/)
{
	throw std::exception();
}