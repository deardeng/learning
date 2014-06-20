#include <iostream>
#include <string>
using namespace std;
#include "StringUtil.h"

int main(void){
	string s = " abcd		";
	StringUtil::LTrim(s);
	cout << "[" << s << "]" << endl;
	s = " abcd		";
	StringUtil::RTrim(s);
	cout << "[" << s << "]" << endl;
	s = " abcd		";
	StringUtil::Trim(s);
	cout << "[" << s << "]" << endl;
	return 0;
}