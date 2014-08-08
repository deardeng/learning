#include "String.h"

int main(void){
	String s1("AAA");
	//String s2("BBB");

	s1.Display();
	String s2=s1;//调用默认的拷贝构造函数
	//系统提供的默认拷贝函数实施的是浅拷贝s2.str_=s1.str_

	String s3;
	s3.Display();
	s3=s2;			//调用等号运算符
					//系统提供的默认等号运算符实施的是浅拷贝
					//s3.str_=s2.str_;
					//s3.operator=(s2);

	//要让对象是独一无二的，我们要禁止拷贝
	//方法是将拷贝构造函数与=运算符声明为私有，
	//并且不提供它们的实现
	return 0;
}