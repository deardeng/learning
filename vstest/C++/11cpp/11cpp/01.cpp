#include "Test.h"

int main(void){
	Test t;
	t.Display();
	Test t1(2);
	t.Display();

	Test* t3 = new Test(20);
	t3->Display();
	delete t3;
	return 0;
}