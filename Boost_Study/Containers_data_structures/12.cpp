#include <iostream>
using namespace std;
class cat
{
	//int len;
	int age;
public:
	cat() { age = 1;}
	~cat() {}
	void miao(void) { cout << "Miao, my age = " << age << endl; }
};
int main(void)
{
	cat kitty;
	int * p = (int *)(&kitty);
	*p = 20;
	kitty.miao();
	return 0;
}