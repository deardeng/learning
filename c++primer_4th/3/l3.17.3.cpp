#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
int main(){
    vector<string> svec;
    string str;
    cout << "Enter text(Ctrl+D to end):" << endl;
    while(cin >> str)
        svec.push_back(str);
    if(svec.size()==0){
        cout << "No string?!" << endl;
        return -1;
    }
    cout << "Transformed elements from the vector:" << endl;
    vector<string>::size_type cnt=0;
    vector<string>::iterator iter;
    for(iter=svec.begin();iter!=svec.end();++iter){
        for(string::size_type index=0;index!=(*iter).size();++index)
            if(islower((*iter)[index]))
                (*iter)[index]=toupper((*iter)[index]);
        cout << *iter << " ";
        ++cnt;
        if(cnt%8==0)
            cout << endl;
    }
    return 0;
}
