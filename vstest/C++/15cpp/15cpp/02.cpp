#include <iostream>
using namespace std;

class Empty{
public:
	Empty* operator&(){
		cout << "AAAA" << endl;
		return this;
	}
	const Empty* operator&()const{
		cout << "BBBB" << endl;
		return this;
	}
};

int main(void){

	Empty e;
	Empty* p=&e;//µÈ¼ÛÓÚe.operator&();
	const Empty e2;
	const Empty *p2=&e2;
	cout << sizeof(Empty) << endl;

	return 0;
}