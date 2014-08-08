#include <iostream>
using namespace std;

int main(void){
	int val=100;
	int &refval=val;
	refval=200;
	cout << "val=" << val << endl;
	return 0;

}
