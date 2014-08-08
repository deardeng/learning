#include "Test.h"
#include <iostream>
using namespace std;

void TestFun(const Test t){

}
void TestFun2(const Test& t){

}
Test TestFun3(const Test& t){
	return t;
}
const Test& TestFun4(const Test& t){
	//return const_cast<Test&>(t);
	return t;
}
int main(void){
	Test t(10);

	/*TestFun(t);
	TestFun2(t);*/
	//t=TestFun3(t);

	//Test& t2 = TestFun3(t);
	//Test t2=TestFun4(t);
	const Test& t2=TestFun4(t);

	cout << "......." << endl;
	return 0;
}