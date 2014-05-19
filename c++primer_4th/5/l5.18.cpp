#include<iostream>
using namespace std;
#include<string>
#include<vector>

int main(){
    vector<string *>spvec;

    string str;
    cout << "Enter some strings(Ctrl+D to end)" << endl;
    while(cin >> str){
        string *pstr = new string;
        *pstr = str;
        spvec.push_back(pstr);
    }
    vector<string *>::iterator iter = spvec.begin();
    while(iter != spvec.end()){
        cout << **iter << (**iter).size() << endl;
        iter++;
    }
    iter = spvec.begin();
    while(iter!=spvec.end()){
        delete *iter;
        iter++;
    }
    return 0;
}
