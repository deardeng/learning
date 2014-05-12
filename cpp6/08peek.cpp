#include <iostream>
using namespace std;
#include <string>
//i.putback(×Ö·û);
//i.peek();
int main()
{
	char buf[100];
	char c;
	cin >> ws;
	c = cin.get();
	//if(cin.get()>='0'&&cin.get()<='9')c = cin.get();
	cin.putback(c);
	if(isdigit(c)){
		double d;
		cin >> d;
		cout << "d=" << d << endl;
	}
	else{
		string s;
		cin >> s;
		cout << "s=" << s << endl;
	}
	cin >> ws;
	if(cin.peek()>='0'&&cin.peek()<='9'){
		double d;
		cin >> d;
		cout << "d=" << d << endl;
	}
	else{
		string s;
		cin >> s;
		cout << "s=" << s << endl;
	}
}
