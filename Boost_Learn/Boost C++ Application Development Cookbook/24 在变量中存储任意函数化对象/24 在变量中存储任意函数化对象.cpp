// std::unary_function<> ģ������Ҫ��
#include <functional>

// Ϊ����int���Ҳ������κζ����ĺ�������һ��typedef
typedef void(*func_t)(int);
// ��������ָ������ָ�룬���Ҷ�����ӵ�е�ÿ���������ñ����ܵĺ���
// �����ܴ����������� :��
void process_integers(func_t f);

// ����������
class int_processor : public std::unary_function<int, void>
{
	const int min_;
	const int max_;
	bool& triggered_;

public:
	int_processor(int min, int max, bool& triggered)
		: min_(min)
		, max_(max)
		, triggered_(triggered)
	{}

	void operator()(int i) const
	{
		if (i < min_ || i > max_)
		{
			triggered_ = true;
		}
	}
};

#include <boost/function.hpp>
typedef boost::function<void(int)> fobject_t;

// ��������������Խ��ܺ���������
void process_integers(const fobject_t& f);

int main()
{
	bool is_triggered = false;
	int_processor fo(0, 200, is_triggered);
	process_integers(fo);
	assert(is_triggered);

	system("pause");
	return 0;
}

void foo(const fobject_t& f)
{
	// boost::function �ǿ���ת����bool��
	if (f)
	{
		// 'f'����ֵ
	}
	else
	{
		// 'f'Ϊ��
		// ...
	}
}

bool g_is_triggered = false;
void set_functional_object(fobject_t& f)
{
	int_processor fo(100, 200, g_is_triggered);
	f = fo;
	// 'fo'�뿪�������ҽ������٣���'f'��ʹ����������Ҳ�ǿ��õ�
}

#include <vector>
#include <algorithm>
#include <boost/bind.hpp>

void foo1()
{
	std::vector<int> v;
	std::for_each(v.begin(), v.end(), boost::bind(std::plus<int>(), 10, _1));

	fobject_t f(boost::bind(std::plus<int>(), 10, _1));
	std::for_each(v.begin(), v.end(), f);
}

void process_integers(const fobject_t& f)
{
	static const int data[] = { 1, 2, 3, 4, 5, 200 };
	std::for_each(data, data + sizeof(data), f);
}