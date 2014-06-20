#include "Test.h"

int main(void){
	Test t[2]={10,20};

	Test* t2 = new Test(2);
	delete t2;
	Test* t3 = new Test[2];
	delete[] t3;
	return 0;
}