#include<boost/spirit/include/phoenix_core.hpp>
#include<boost/spirit/include/phoenix_operator.hpp>
#include<assert.h>
#include<boost/spirit/include/qi.hpp>
#include <algorithm>
#include <functional>


//��������������ͣ�������Դ�ļ��ж�������ͷ�ļ��б�д��������Ҳע�⴫�ݵ�
//boost::spirit::parse�����ĵ��������ͣ�ʹ�õĵ������Ĳ�ͬ����Խ�٣��õ��Ķ������ļ���С��ԽС��
//��Դ�ļ���д����������һ���ô��������ή����Ŀ�����ٶȣ�ע�⵽��Spirit���������뻺����
//�����������Դ�ļ�����һ�Σ���������ͷ�ļ��ж������ǲ���������Ŀ��ʹ�ô��ļ�����
struct date
{
	unsigned short year;
	unsigned short month;
	unsigned short day;
};

date parse_date_time1(const std::string& s)
{
	using boost::spirit::qi::_1;
	using boost::spirit::qi::ushort_;
	using boost::spirit::qi::char_;
	using boost::phoenix::ref;

	date res;
	const char* first = s.data();
	const char* const end = first + s.size();
	bool success = boost::spirit::qi::parse(first, end,
		ushort_[ref(res.year) = _1] >> char_('-')
		>> ushort_[ref(res.month) = _1] >> char_('-') >>
		ushort_[ref(res.day) = _1]
		);

	//���C++11 lambda���ʽ��дYYYY����ݣ��Ĺ���but��֪Ϊ��
	//NOTE:    error C3750: ��&��: �����б��е�������
	//bool success = boost::spirit::qi::parse(first, end, ushort_[ [&res](unsigned short s) {res.year = s; }] >> char_('-') >> ushort_[ref(res.month) = _1] >> char_('-') >> ushort_[ref(res.day) = _1]);
	if (!success || first != end)
	{
		throw std::logic_error("Parsing failed");
	}

	return res;
}

date parse_date_time2(const std::string& s)
{
	using boost::spirit::qi::_1;
	using boost::spirit::qi::uint_parser;
	using boost::spirit::qi::char_;
	using boost::phoenix::ref;

	//ʹ��unsigned short��Ϊ������ͣ���Ҫʮ���ƣ�����2λ��2λ������
	uint_parser<unsigned short, 10, 2, 2> u2_;

	//ʹ��unsigned short��Ϊ������ͣ���Ҫʮ���ƣ�����4λ��4λ������
	uint_parser<unsigned short, 10, 4, 4> u4_;

	date res;
	const char* first = s.data();
	const char* const end = first + s.size();
	bool success = boost::spirit::qi::parse(first, end, u4_[ref(res.year) = _1]
	>> char_('-') >> u2_[ref(res.month) = _1] >> char_('-') >> u2_[ref(res.day) = _1]
		); 

	if (!success || first != end)
	{
		throw std::logic_error("Parsing failed");
	}

	return res;
}

int main()
{
	date d = parse_date_time1("2016-1-14");
	assert(d.year == 2016);
	std::cout << d.month << std::endl;
	assert(d.month == 1);
	assert(d.day == 14);

	parse_date_time1("2016-1-14");
	assert(d.year == 2016);
	assert(d.month == 1);
	assert(d.day == 14);

	try
	{
		parse_date_time2("12345-12-31");
		assert(false);
	}
	catch(const std::logic_error&){}

	system("pause");
	return 0;
}