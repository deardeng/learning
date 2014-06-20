#ifndef	_B_H_
#define _B_H_
class A;
class B
{
public:
	B(void);
	~B(void);
	void fun(A& a){

	}
	
	A* a_;//前向声明的类不能实例化对象
};
#endif//_B_H_ 