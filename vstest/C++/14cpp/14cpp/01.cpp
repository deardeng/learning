#include "Test.h"

int main(void){
	Test t(10);
	Test t2=t;//�ȼ���Test t2(t);
	//Test t2(t);//���ÿ������캯��
	return 0;
}