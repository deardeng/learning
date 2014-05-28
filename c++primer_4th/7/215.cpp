#include<iostream>
using namespace std;

char &get_val(string &str,string::size_type ix){
    return str[ix];
}

int main(){
    string s("a value");
    cout << s << endl;
    get_val(s,0)='A';

    cout << s << endl;
    return 0;
}
