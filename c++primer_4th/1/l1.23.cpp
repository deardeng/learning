#include<iostream>
using namespace std;
#include"Sales_item.h"

int main(){
	Sales_item total,trans;
	cout << "Enter transactions: " << endl;
	if(cin >> total){
		while(cin >> trans)
			if(total.same_isbn(trans))
				total = total + trans;
			else{
				cout <<"Different ISBN." << endl;
				return -1;
			}
	cout << "The total information:" << endl << "ISBN,number of copies sold,"
	<< " total revenue,and average price are:" << endl << total;
	}
	else{
		cout << "NO data?!" << endl;
		return -1;
	}
	return 0;
}