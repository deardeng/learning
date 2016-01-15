#include<boost/optional.hpp>
#include<iostream>
#include<stdlib.h>
#include <time.h>

class locked_device
{
	explicit locked_device(const char* /*param*/)
	{
		//����ӵ�ж��豸�Ķ�ռʽ����
		std::cout << "Device is locked\n";//�豸������
	}
public:
	~locked_device()
	{
		//�ͷ��豸��
	}
	void use()
	{
		std::cout << "Success!\n";//�ɹ�
	}
	static boost::optional<locked_device> try_lock_device()
	{
		if (rand() % 2)
		{
			//δ�������豸
			return boost::none;
		}
		//�ɹ���
		return locked_device("device name");//�豸��
	}
};

int main()
{
	//Boost��һ����ΪRandom�Ŀ⡣�������֪��Ϊʲô
	//��stdlib.h����rand()����ʱ��Ҫ��д�����μ�90
	srand((unsigned)time(NULL));
	for (unsigned i = 0; i < 10; ++i)
	{
		boost::optional<locked_device> t = locked_device::try_lock_device();
		//optional�ܹ�ת��Ϊbool����
		if (t)
		{
			t->use();
			system("pause");
			return 0;
		}
		else
		{
			std::cout << "...trying again\n";//����
		}
	}
	std::cout << "Failure!\n";//ʧ��
	system("pause");
	return -1;
}