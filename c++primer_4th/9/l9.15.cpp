#include <iostream>
using namespace std;
#include <list>
#include <string>

int main(){
    list<string> slst;
    string str;

    cout << "Enter some strings(Ctrl+D to end):" << endl;
    while(cin >> str)
        slst.push_back(str);

    for(list<string>::iterator iter=slst.begin();iter!=slst.end();++iter)
        cout << *iter << endl;
    return 0;
}
