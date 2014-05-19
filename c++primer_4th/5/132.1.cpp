#include<iostream>
using namespace std;
#include<string>

int main(){
    string s("Expressions in C++ are composed . . .");
    string::iterator it = s.begin();
    while(it != s.end()){
        if(it==s.begin()||isspace(*(it-1)))
            *it = toupper(*it);
        ++it;
    }
    cout << s << endl;
}
