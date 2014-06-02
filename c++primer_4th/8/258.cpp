#include<iostream>
using namespace std;
#include<sstream>

int main(){
    int val1=512,val2=1024;
    ostringstream format_message;
    format_message << "val1: " << val1 << "\n"
        << "val2: " << val2 << "\n";
    cout << format_message.str();//返回format_message中存储的string类型对象
    istringstream input_istring(format_message.str());
    string dump;
    input_istring >> dump >> val1 >> dump >> val2 ;
    cout << val1 << " " << val2 << endl;
}
