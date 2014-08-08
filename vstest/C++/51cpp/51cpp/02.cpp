#include <iostream>
using namespace std;


class Test{
public:
	Test(){
			cout << "Test..." << endl;
	}
	Test(const Test& other){
		cout << "Copy Test..." << endl;
	}
	~Test(){
		cout << "~Test" << endl;
	}
};
Test fun(){
	/*Test t;
	return t;*/
	return Test();
}
int main(void){
	fun();
	cout << "........." << endl;
	return 0;
}