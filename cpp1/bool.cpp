#include <iostream>
using namespace std;

int main()
{
	bool gender = true;
	bool sex = false;
	cout << (gender?"˧��":"��Ů") << endl;
	cout << (sex?"˧��":"��Ů") << endl;
	cout << gender << ',' << sex << endl;
	cout << boolalpha << gender << ',' << sex << endl;
}

