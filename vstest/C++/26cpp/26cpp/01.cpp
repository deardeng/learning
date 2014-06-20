#include <string>
#include <iostream>
using namespace std;

int main(void){
	string s1;
	string s2("abcdefghijkl");
	cout << s2 << endl;

	basic_string<char> s3("xxx");
	cout << s3 << endl;

	string s4("abcdefg",4);
	cout << s4 << endl;
	
	string s5(s2,2,3);
	cout << s5 << endl;
	
	string::iterator first=s2.begin()+1;
	string::iterator last=s2.begin()+3;

	string s6(first,last);	//[first,last)
	cout << s6 << endl;
	return 0;
}