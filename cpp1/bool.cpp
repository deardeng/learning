#include <iostream>
using namespace std;

int main()
{
	bool gender = true;
	bool sex = false;
	cout << (gender?"帅哥":"美女") << endl;
	cout << (sex?"帅哥":"美女") << endl;
	cout << gender << ',' << sex << endl;
	cout << boolalpha << gender << ',' << sex << endl;
}

