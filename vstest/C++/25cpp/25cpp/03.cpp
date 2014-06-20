#include <iostream>
using namespace std;

class Test{
public:
	Test(int n):n_(n){
		cout << "Test(int n):n_(n)" << endl;
	}
	Test(const Test& other){
		cout << "Test(const Test& other)" << endl;
	}
	~Test(){
		cout << "~Test()" << endl;
	}
	void* operator new(size_t size){
		cout << "void* operator new(size_t size)" << endl;
		void *p = malloc(size);
		return p;
	}
	void operator delete(void *p){
		cout << "void operator delete(void *p)" << endl;
		free(p);
	}
	void operator delete(void *p,size_t size){
		cout << "void operator delete(void *p,size_t size)" << endl;
		free(p);
	}
	void* operator new(size_t size,const char* file,long line){
		cout << file << ":" << line << endl;
		void *p = malloc(size);
		return p;
	}
	void operator delete(void *p,const char* file,long line){
		cout << file << ":" << line << endl;
		free(p);
	}
	void* operator new(size_t size,void *p){
		return p;
	}

	void  operator delete(void *, void *){}
	int n_;
};
void* operator new(size_t size){
	cout << "global void* operator new(size_t size)" << endl;
	void *p = malloc(size);
	return p;
}
void operator delete(void *p){
	cout << "global void operator delete(void *p)" << endl;
	free(p);
}
void* operator new[](size_t size){
	cout << "global void* operator new[](size_t size)" << endl;
	void *p = malloc(size);
	return p;
}
void operator delete[](void *p){
	cout << "global void operator delete[](void *p)" << endl;
	free(p);
}
int main(void){
	Test *p1 = new Test(100);//new operator = operator new + ���캯��
	delete p1;
	char* str=new char[100];
	delete[] str;
	char chunk[10];
	Test *p2 = new (chunk) Test(200);//operator new(size_t,void *_Where)
									//placement new,�������ڴ� + ���캯���ĵ���
	cout << p2->n_ << endl;
	p2->~Test();	//��ʾ������������
	//Test *p3=(Test*)chunk;
	Test *p3 = reinterpret_cast<Test*>(chunk);
	cout << p3->n_ << endl;

#define new new(__FILE__,__LINE__)
	//Test* p4 = new(__FILE__,__LINE__)Test(300);
	Test *p4=new Test(300);
	delete p4;


	return 0;
}