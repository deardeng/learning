#include<iostream>
using namespace std;
#include"Sales_item.h"

int main()
{
	Sales_item item1,item2;
	cin >> item1 >> item2;
	if(item1.same_isbn(item2)){
		cout << item1 + item2 << endl;
		return 0;
	}else{
		cerr << "Data must refer to same ISBN" << endl;
		return -1;
	}
}