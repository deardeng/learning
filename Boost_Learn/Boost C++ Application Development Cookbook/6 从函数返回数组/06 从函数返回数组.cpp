#include<boost/array.hpp>
#include<algorithm>

//��ֵ����1�ĺ���������
struct add_1:public std::unary_function<char,void>
{
	void operator()(char& c)const
	{
		++c;
	}
	//���û�������д���������󣬵��ǲ�֪��'boost::bind(std::plus<char>(), _1, 1)'
	//������ʲô����ôreading 9
};

typedef boost::array<char, 4> array4_t;
array4_t& vector_advance(array4_t& val)
{
	//boost::array��begin(),cbegin(),end(),cend(),
	//rbegin(),size(),empty()����������STL���������ĺ���
	std::for_each(val.begin(), val.end(), add_1());
	return val;
}

int main()
{
	//��C++11�У����ǿ��Ծ����ʼ��һ������������ʼ��boost::array;
	//array4_t val = {0, 1, 2, 3};
	//����C++03�У���Ҫ��Ӷ����һ�Դ�����
	array4_t val = { {0,1,2,3} };

	//boost::array����;����һ��ƽ�������飻
	array4_t val_res;//���ֵ����֧��Ĭ�ϵĹ��캯���͸�ֵ��
	val_res = vector_advance(val);//�����Ա�Ĭ�Ϲ��첢���ǿɸ�ֵ��
	assert(val.size() == 4);
	assert(val[0] == 1);
	/*val[4];*/   //�ᴥ��һ�����ԣ���Ϊ��������Ϊ3
	//���ǿ���ʹ��������ڱ���ʱ�������μ�30
	assert(sizeof(val) == sizeof(char) * array4_t::static_size);
	system("pause");
	return 0;
}