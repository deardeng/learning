#ifndef _STRING_UTIL_H_
#define _STRING_UTIL_H_

#include <string>
#include <iostream>
using namespace std;
class StringUtil
{
public:
	static void LTrim(string& s);
	static void RTrim(string& s);
	static void Trim(string &s);
};

#endif //_STRING_UTIL_H_