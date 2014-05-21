#include<iostream>
using namespace std;
#include<string>

int main(){
    int i=1000;
    int *ip=&i;
    char *pc=reinterpret_cast<char *>(ip);
    string str(pc);
    cout << pc << endl;
}
