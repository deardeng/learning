#include <iostream>
using namespace std;
#include <string>
class MyException{
public:
	MyException(const char* message)
		:message_(message){
			cout << "MyException..." << endl;
	}
	MyException(const MyException& other):message_(other.message_){
		cout << "Copy MyException..." << endl;
	}
	~MyException(){
		cout << "~MyException" << endl;
	}
	const char* what() const{
		return message_.c_str();
	}
private:
	string message_;
};

class Test{
public:
	Test(){
		cout << "Test..." << endl;
	}
	Test(const Test& other){
		cout << "Copy Test..." << endl;
	}
	~Test(){
		cout << "~Test..." << endl;
	}
};
class Obj{
public:
	Obj(){
		cout << "Obj..." << endl;
	}
	Obj(const Obj& other){
		cout << "Copy Obj..." << endl;
	}
	~Obj(){
		cout << "~Obj..." << endl;
	}
};
class Test3{
public:
	Test3(){
		cout << "Test3..." << endl;
	}
	Test3(const Test3& other){
		cout << "Copy Test3..." << endl;
	}
	~Test3(){
		cout << "~Test3..." << endl;
		throw 4;
	}
};
class Test2{
public:
	Test2(){
		obj_ = new Obj;
		cout << "Test2..." << endl;
		throw MyException("test exception2");
	}
	Test2(const Test2& other){
		cout << "Copy Test2..." << endl;
	}
	~Test2(){
		delete obj_;
		cout << "~Test2..." << endl;
	}
private:
	Obj* obj_;
};


int main(void){

	try{
		/*Test t;
		throw MyException("test exception");*/
		/*Test2 t2;*/
		
		Test3 t3;
		throw MyException("Test exception3");
		
	}
	catch(MyException& e){
		
		cout << e.what() << endl;
	}
	catch(int){
		cout << "catch a int exception" << endl;
	}
}
