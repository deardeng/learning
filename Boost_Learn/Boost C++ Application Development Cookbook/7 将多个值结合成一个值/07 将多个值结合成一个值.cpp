#include<boost/tuple/tuple.hpp>
#include<boost/tuple/tuple_comparison.hpp>
#include<set>
#include<string>
#include<cassert>

int main()
{
	boost::tuple<int, std::string> almost_a_pair(10, "Hello");
	boost::tuple<int, float, double, int> quad(10, 1.0f, 10.0, 1);

	//boost::get<>���������������ʽ���㷺��������Boost
	int i = boost::get<0>(almost_a_pair);
	const std::string& str = boost::get<1>(almost_a_pair);
	double d = boost::get<2>(quad);

	using namespace boost;
	
	//Ԫ��Ƚϲ�������ͷ�ļ�"boost/tuple/tuple_comparison.hpp"�ж��壬set�Ƚ�Ҫ��
	std::set< tuple<int, double, int> > s;
	s.insert(make_tuple(1, 1.0, 2));
	s.insert(make_tuple(2, 10.0, 2));
	s.insert(make_tuple(3, 100.0, 2));

	auto t = make_tuple(0, -1.0, 2);
	assert(2 == get<2>(t));

	boost::tuple<int, float, double, int> quadd(10, 1.0f, 10.0, 1);
	int ii;
	float f;
	double dd;
	int i2;

	//��'quad'������ֵ��'ii','f','dd','i2'����
	boost::tie(ii, f, dd, i2) = quadd;
	assert(ii == 10);
	assert(i2 == 1);


	system("pause");
	return 0;
}