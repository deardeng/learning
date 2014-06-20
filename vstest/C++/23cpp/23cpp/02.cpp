#include "String.h"
#include <iostream>
using namespace std;

int main(void){
	String s1("abc");
	String s2(s1);

	String s3;
	s3=s1;
	s3.Display();
	s3="xxxx";
	s3.Display();
	
	
	String s4;
	bool notempty;
	notempty = !s4;
	cout << notempty << endl;

	s4="aaaa";
	notempty = !s4;
	cout << notempty << endl;
	return 0;

}