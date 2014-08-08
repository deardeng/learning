#include <iostream>
using namespace std;

//对于一个没有任何接口的类，如果想要将它定义成
//抽象类，只能将虚析构函数声明为纯虚的
//通常情况下在基类中纯虚函数不需要实现
//例外是纯虚析构函数要给出实现。（给出一个空的实现即可）
class Base{
public:
	virtual ~Base()=0{

	}
};
class Drived : public Base{

};
int main(void){
	Drived d;
	return 0;
}