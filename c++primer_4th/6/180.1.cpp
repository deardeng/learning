#include<iostream>
using namespace std;
#include<string>
#include<vector>

int main(){
    vector<string> svec(3);
    for(vector<string>::size_type ind=0;ind!=svec.size();++ind){
        cin >> svec[ind];
    }
    vector<string>::iterator iter = svec.begin();
    for(;iter != svec.end();iter++)
        cout << *iter << '|';
    cout << "\b ";
    cout << endl;
}
