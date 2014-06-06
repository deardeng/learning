#include <iostream>
using namespace std;
#include <vector>
#include <string>

int main(){
    vector<string> svec;
    string str;

    cout << "Enter some strings(Ctrl+D to end)" << endl;
    while(cin >> str)
        svec.push_back(str);

    for(vector<string>::iterator iter=svec.begin();iter!=svec.end();++iter)
        cout << *iter << endl;
    return 0;
}
