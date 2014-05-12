#include <iostream>
using namespace std;
char mem[10000];
int pos=0;
class A{
public:
	A(){cout<<"A()"<<endl;}
	~A(){cout<<"~A()"<<endl;}
	static void* operator new(size_t bytes){
		cout<<"new A"<<bytes<<endl;
		int alloc = pos;
		pos += bytes;
		return mem+alloc;
	}
	static void operator delete(void* p){
		cout<<"delete A"<<endl;
	}
	static void* operator new[](size_t bytes){
		cout<<"new[] A"<<bytes<<endl;
		int alloc = pos;
		pos += bytes;
		return mem+alloc;
	}
	static void operator delete[](void* p){
		cout<<"delete[] A"<<endl;
	}
};
void* operator new(size_t bytes)
{cout<<"new "<<bytes<<endl;return mem;}
void operator delete(void* p)
{cout<<"delete "<<endl;}
int main()
{
	A* x = new A;//1、分配空间；2、执行构造函数
	delete x;//1、执行析构函数；2、释放空间
	x = new A[3];
	delete[] x;
	int* p = new int;
	delete p;
}
