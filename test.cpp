#include <iostream>
using namespace std;
class Test{
    public:
        Test(){

        }
        ~Test(){

        }

        static const int x_ =100;//静态成员的引用性说明
};
//const int Test::x_=200;

int main(void){
    cout << Test::x_ << endl;
}
