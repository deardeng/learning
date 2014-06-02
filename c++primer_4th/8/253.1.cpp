#include<iostream>
using namespace std;
#include<vector>
#include<fstream>

int main(){
    string s;
    vector<string> files(3);
    for(vector<string>::iterator it=files.begin();it!=files.end();it++){
        cin >> *it;
    }
    vector<string>::const_iterator it = files.begin();
    while(it!=files.end()){
        ifstream input(it->c_str());
        if(!input)
            break;
        while(input >> s)
            cout << s;
        ++it;
    }
}
