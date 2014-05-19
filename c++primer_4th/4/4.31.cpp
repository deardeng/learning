#include<iostream>
using namespace std;
#include<string>
#include<cstring>

int main(){
    string in_str;
    const size_t str_size=10;
    char result_str[str_size+1];
    cout << "Enter a string(<=" << str_size << " characters):" << endl;
    cin >> in_str;

    size_t len = strlen(in_str.c_str());
    if(len>str_size){
        len=str_size;
        cout << "String is longer than " << str_size << 
            " characters and stored only " << str_size << 
            " characters!" << endl;
    }
    strncpy(result_str,in_str.c_str(),len);
    result_str[len]='\0';
    cout << result_str << endl;
    return 0;
}
