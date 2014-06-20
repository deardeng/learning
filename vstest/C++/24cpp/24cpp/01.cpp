#include "String.h"
#include <iostream>
using namespace std;

int main(void){
	String s1("abcdefg");
	char ch=s1[2];
	cout << ch << endl;
	s1[2]='A';
	s1.Display();

	const String s2("xyzabc");
	ch=s2[2];
	//s2[2] = 'M';
	s2.Display();

	String s3="xxx";
	String s4="yyy";

	String s5=s3+s4;
	s5.Display();

	String s6 = "aaa" + s3 + "abcdef";
	s6.Display();

	s3+=s4;
	s3.Display();

	cout << s3 << endl;

	String s7;
	cin >> s7;
	cout << s7 << endl;

	return 0;
}