//BOOST_ALL_DYN_LINK;
//PATH = %PATH%; D:\boost_dir\libs64;
//�˴���PATH����Ҫ�У������������ok��ִ�е�ʱ���Ҳ���dll��Ҫ��D:\boost_dir\libs64�е�dll��������ǰĿ¼�£��ſ���ִ�С�


#include<boost/program_options.hpp>
//'reading_file' �쳣����errors.hpp������
#include<boost/program_options/errors.hpp>
#include<iostream>
#include<cstdlib>
//�����
namespace opt = boost::program_options;

int main(int argc, char* argv[])
{
	//����һ��ѡ������������������һ���ı�������"All options"(����ѡ��)
	opt::options_description desc("All options");
	
	//���������ѡ��ʱ����1������������������ʹ�õ�����
	//��2���������Ǹ�ѡ������ͣ�����value<>���а�װ
	//��3�������Ƕ��Ǹ�ѡ���һ����̵�����
	//'a'��'o'�ֱ���"apples"��"oranges"ѡ��ļ��
	//��Ϊ'name'ѡ��û�б���עΪ'required()',�����û����ܲ�֧����
	desc.add_options()
		("apples,a", opt::value<int>()->default_value(10), "apples that you have")
		("oranges,o", opt::value<int>(), "oranges that you have")
		("name", opt::value<std::string>(), "your name")
		("help", "produce help message");

	//���ڱ��������в����ı���
	opt::variables_map vm;

	//�������洢����
	opt::store(opt::parse_command_line(argc, argv, desc), vm);
	//Ҳ������'parse_environment'����������������
	opt::notify(vm);
	if (vm.count("help"))
	{
		std::cout << desc << "\n";
		system("pause");
		return 1;
	}

	//��"apples_oranges.cfg"�����ļ���Ӷ�ʧ��ѡ��
	//Ҳ�����ṩһ��������������(istreamable)�Ķ�����Ϊ'parse_config_file'�ĵ�һ������
	//'char'ģ������������ݸ��ײ��std::basic_istream����
	try
	{
		opt::store(
			opt::parse_config_file<char>("apples_oranges.cfg", desc), vm);
	}
	catch (const opt::reading_file& e)
	{
		std::cout << "Failed to open file 'apples_oranges.cfg': " << e.what();//��apples_oranges.cfg�ļ�ʧ��
	}

	opt::notify(vm);
	if (vm.count("name"))
	{
		std::cout << "Hi, " << vm["name"].as<std::string>() << "!\n";
	}

	std::cout << "Fruits count: " << vm["apples"].as<int>() + vm["oranges"].as<int>() << std::endl;//ˮ������

	system("pause");
	return 0;
}