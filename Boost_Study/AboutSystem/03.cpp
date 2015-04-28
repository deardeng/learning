#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/make_shared.hpp>
#include <cstddef>
#include <stdexcept>
#include <boost/operators.hpp>
#include <boost/assert.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/config.hpp>
#include <boost/noncopyable.hpp>
#include <boost/static_assert.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/cstdint.hpp>
#include <limits>
#define BOOST_SYSTEM_NO_LIB
#include <boost/system/error_code.hpp>
using namespace boost::system;

class my_category : public error_category
{
public:
	virtual const char* name() const
	{
		return "myapp_category";
	}
	virtual std::string message(int ev) const
	{
		std::string msg;
		switch (ev)
		{
		case 0:
			msg = "ok";
			break;
		default:
			msg = "some error";
			break;
		}
		return msg;
	}
};



int main()
{
	my_category my_cat;
	error_code ec(10, my_cat);
	std::cout << ec.value() << ec.message() << std::endl;
	ec = error_code(10, system_category());
	std::cout << ec.value() << ec.message() << std::endl;

	//ERROR
	//error_code�Ĺ��캯�����ܵ���error_category�����ã����´��������
	// ������Ȼ������ȷ���룬������ʱ��Ϊ��ʱ���������������������ڵ���message()��Ա����ʱ�ᷢ��δ������Ϊ��
	{
		ec = error_code(10, my_category());
		std::cout << ec.value() << ec.message() << std::endl;
	}
}