#include<iostream>
using namespace std;
#include<sstream>
#include<string>
#include <vector>
#include"l8.3.get.h"

int main(){
    string line;
    cout << "Enter a line of text:" << endl;
    getline(cin,line);
    //line += ' ';
    istringstream isstr(line);
    string word;
    vector<string> vec;
    while(isstr >> word ){
        vec.push_back(word);
    }
    for(auto &w : vec){
        cout << w << endl;
    }
    //cout << "the current linestream: " << isstr.str() << endl;
    //get(isstr);
    return 0;
}
