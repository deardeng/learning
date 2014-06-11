#include <iostream>
using namespace std;
#include <fstream>

int main(int argc, const char *argv[])
{
    string a="1.txt";
    ofstream f1(a.c_str());
    if(!f1)
        cout << "error";
    string ab;
    while(cin >> ab){
        f1 << ab;
    }
    return 0;
}
