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
    ifstream input;
    while(it!=files.end()){
        input.open(it->c_str());
        if(!input){
            cerr << "error: can not open file: " << *it << endl;
            input.clear();
            ++it;
            continue;
        }
        while(input >> s)
            cout << s;
        input.close();
        input.clear();
        ++it;
    }
}
