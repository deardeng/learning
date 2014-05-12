#include<iostream>
using namespace std;
#include<string>

int main(){
    string line;
    while(getline(cin,line))
        cout << line << endl;
    return 0;
}
