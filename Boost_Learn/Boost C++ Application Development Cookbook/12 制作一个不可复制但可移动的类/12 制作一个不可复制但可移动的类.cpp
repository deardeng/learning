#include<boost/noncopyable.hpp>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<assert.h>

//��һ���޷����Ƶ���Դ����Ӧ�������������б���ȷ�ͷţ����Ҵ�һ������������
class descriptor_owner : private boost::noncopyable
{
	void* descriptor_;

public:
	descriptor_owner() :descriptor_(NULL){}
	explicit descriptor_owner(const char* param):descriptor_(_strdup(param)){}

	void swap(descriptor_owner& desc)
	{
		std::swap(descriptor_, desc.descriptor_);
	}
	~descriptor_owner()
	{
		free(descriptor_);
	}
};

////noncopyable error C2280: ��descriptor_owner::descriptor_owner(const descriptor_owner &)��: ����������ɾ���ĺ���
//descriptor_owner construct_descriptor()
//{
//	return descriptor_owner("Construct using this string");
//	//������ַ�������
//}

//����ʹ��swap��������������
void construct_descriptor1(descriptor_owner& ret)
{
	descriptor_owner("Construct using this string").swap(ret);
}

//�������Ľ������������������STL��Boost������ʹ��descriptor_owner�����⣬��������̫���¡�

#include<boost/config.hpp>

//ֻ�����ƶ���descriptor_owner��
#if !defined(BOOST_NO_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

class descriptor_owner1
{
	void* descriptor_;

public:
	descriptor_owner1() :descriptor_(NULL) {}
	explicit descriptor_owner1(const char* param) :descriptor_(_strdup(param)) {}

	descriptor_owner1(descriptor_owner1&& param) :descriptor_(param.descriptor_)
	{
		param.descriptor_ = NULL;
	}

	descriptor_owner1& operator=(descriptor_owner1&& param)
	{
		clear();
		std::swap(descriptor_, param.descriptor_);
		return *this;
	}

	void clear()
	{
		free(descriptor_);
		descriptor_ = NULL;
	}
	
	bool empty()const
	{
		return !descriptor_;
	}

	~descriptor_owner1()
	{
		clear();
	}
};

descriptor_owner1 construct_descriptor2()
{
	return descriptor_owner1("Construct using this string");
}

void foo_rv()
{
	std::cout << "C++11\n";
	descriptor_owner1 desc;
	desc = construct_descriptor2();
	assert(!desc.empty());
}
#else
void foo_rv()
{
	std::cout << "no C++11\n";
}
#endif 

#include <boost/move/move.hpp>
#include <boost/container/vector.hpp>

//�����ƶ��������Ը��Ƶ���
class descriptor_owner_movable
{
private:
	void *descriptor_;
	BOOST_MOVABLE_BUT_NOT_COPYABLE(descriptor_owner_movable)
public:
	descriptor_owner_movable()
		:descriptor_(NULL)
	{}

	explicit descriptor_owner_movable(const char* param)
		:descriptor_(_strdup(param))
	{}

	descriptor_owner_movable(BOOST_RV_REF(descriptor_owner_movable) param) BOOST_NOEXCEPT//�ƶ�����
		: descriptor_(param.descriptor_)
	{
		param.descriptor_ = NULL;
	}

	descriptor_owner_movable& operator=(BOOST_RV_REF(descriptor_owner_movable) param) BOOST_NOEXCEPT//�ƶ���ֵ
	{
		clear();
		std::swap(descriptor_, param.descriptor_);
		return *this;
	}
	
	void clear()
	{
		free(descriptor_);
		descriptor_ = NULL;
	}
	
	bool empty()const
	{
		return !descriptor_;
	}

	~descriptor_owner_movable()BOOST_NOEXCEPT
	{
		clear();
	}
};

descriptor_owner_movable construct_descriptor3()
{
	return descriptor_owner_movable("Construct using this string");
}

#ifndef YOUR_PROJECT_VECTOR_HPP
#define YOUR_PROJECT_VECTOR_HPP

#include<boost/config.hpp>

//ȷʵ����ֵ
#if !defined(BOOST_NO_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

#include<vector>
namespace your_project_namespace
{
	using std::vector;
}

#else
//û����ֵ
#include<boost/container/vector.hpp>
namespace your_project_namespace
{
	using boost::container::vector;
}

#endif //!defined(BOOST_NO_RVALUE_REFERENCES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

#endif //YOUR_PROJECT_VECTOR_HPP


int main()
{
	foo_rv();

	descriptor_owner_movable movable;
	movable = construct_descriptor3();

	boost::container::vector<descriptor_owner_movable> vec;
	vec.resize(10);
	vec.push_back(construct_descriptor3());

	vec.back() = boost::move(vec.front());

	your_project_namespace::vector<descriptor_owner_movable> v;
	v.reserve(10);
	v.push_back(construct_descriptor3());
	v.back() = boost::move(v.front());

	system("pause");
	return 0;
}