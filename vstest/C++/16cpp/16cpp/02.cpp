#include <iostream>
using namespace std;
class Test{
public:
	Test(){

	}
	~Test(){

	}

	static const int x_ ;//��̬��Ա��������˵��
};
const int Test::x_=200;		//��̬��Ա�Ķ�����˵��
int main(void){
	cout << Test::x_ << endl;
}