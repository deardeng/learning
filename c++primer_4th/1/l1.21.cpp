#include<iostream>
using namespace std;
#include"Sales_item.h"

int main()
{
	Sales_item item;
	cout << " Input some book's ISBN " << endl;
	while(cin >> item){
		cout <<item <<endl;
	}
	return 0;
}