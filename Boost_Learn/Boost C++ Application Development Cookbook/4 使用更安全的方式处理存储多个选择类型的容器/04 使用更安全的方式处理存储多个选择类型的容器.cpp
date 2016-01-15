////sample 1
//#include<boost/any.hpp>
//#include<vector>
//#include<string>
//#include<typeinfo>
//#include<algorithm>
//#include<iostream>
//
////��Щtypedef�ͷ��������������ǵ�ͷ�ļ��У����Ա��ص�SQL�ӿڽ��а�װ
//typedef boost::any cell_t;
//typedef std::vector<cell_t> db_row_t;
//
////�������һ�����ӣ�û��ʵ�ʲ������ݿ�
////db_row_t get_row(const char* /*query*/)
//db_row_t get_row(const char* query)
//{
//	//��ʵ��Ӧ�ó�����'query'����Ӧ������'const char*'
//	//��'const std::string&'�����𣿲μ�60���õ���
//	db_row_t row;
//	row.push_back(10);
//	row.push_back(10.1f);
//	row.push_back(std::string("hello again"));
//	return row;
//}
//
////�����û����ʹ�������ķ���
//struct db_sum :public std::unary_function<boost::any, void>
//{
//private:
//	double& sum_;
//public:
//	explicit db_sum(double& sum) :sum_(sum)
//	{}
//
//	void operator()(const cell_t& value)
//	{
//		const std::type_info& ti = value.type();
//		if (ti == typeid(int))
//		{
//			sum_ += boost::any_cast<int>(value);
//		}
//		else if (ti == typeid(float))
//		{
//			sum_ += boost::any_cast<float>(value);
//		}
//	}
//};
//
//int main()
//{
//	db_row_t row = get_row("Query:����ive me some row, please.");
//	double res = 0.0;
//	std::for_each(row.begin(), row.end(), db_sum(res));
//	std::cout << "Sum of arithmetic types in database row is: " << res
//		<< std::endl;//���ݿ������������еĺϼ���:
//	system("pause");
//	return 0;
//}


//sample2
#include<boost/variant.hpp>
#include<vector>
#include<string>
#include<iostream>

//��Щtypedef�ͷ��������������ǵ�ͷ�ļ��У����Ա��ص�SQL�ӿڽ��а�װ
typedef boost::variant<int, float, std::string> cell_t;
typedef std::vector<cell_t> db_row_t;

//�������һ�����ӣ�û��ʵ�ʲ������ݿ�
db_row_t get_row(const char* /*query*/)
{
	//�μ�60�����п����ҵ�'query'������һ�����õ�����
	db_row_t row;
	row.push_back(10);
	row.push_back(10.1f);
	row.push_back("hello again");
	return row;
}

//���Ƕ�ֵ�������Ĵ���������ǵķÿ�û�з���ֵ��
//�����ṩ��ģ�������boost::static_visitor<>
struct db_sum_visitor :public boost::static_visitor<double>
{
	double operator()(int value) const
	{
		return value;
	}
	double operator()(float value) const
	{
		return value;
	}
	double operator()(const std::string& /*value*/)const
	{
		return 0.0;
	}
};

int main()
{
	db_row_t row = get_row("Query: Give me some row, please.");
	//��ѯ�����ṩһЩ��
	double res = 0.0;
	db_row_t::const_iterator it = row.begin(), end = row.end();
	for (; it != end; ++it)
	{
		res += boost::apply_visitor(db_sum_visitor(), *it);
	}
	std::cout << "Sum of arithmetic types in database row is: " << res << std::endl;
	system("pause");
	return 0;
}