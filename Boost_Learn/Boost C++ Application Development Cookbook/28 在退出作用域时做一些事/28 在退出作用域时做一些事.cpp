#define  _CRT_SECURE_NO_WARNINGS

#include<boost/scope_exit.hpp>
#include<cstdlib>
#include<cstdio>
#include<cassert>


// Ϊ����һ����Ա�������沶׽���� ����ʹ���������this_;
class theres_more_example
{
public:
	void close(std::FILE*) {}

	void theres_more_example_func()
	{
		std::FILE* f = 0;
		BOOST_SCOPE_EXIT(f, this_)
		{
			// �������'this_'
			this_->close(f);
		} BOOST_SCOPE_EXIT_END
	}
};


int main()
{
	theres_more_example test;
	test.theres_more_example_func();

	std::FILE* f = std::fopen("example_file.txt", "w");
	BOOST_SCOPE_EXIT(&f)
	{
		// �������������з�����ʲô������ִ����δ��룬���ҽ���ȷ�ر��ļ�
		std::fclose(f);
	} BOOST_SCOPE_EXIT_END
		// һЩ�����׳��쳣�򷵻صĴ���

		system("pause");
	return 0;
}