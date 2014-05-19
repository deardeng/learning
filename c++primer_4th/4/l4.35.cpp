#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<cstring>

int main(){
    vector<string> svec;
    string str;

    cout << "Enter strings:(Ctrl+D to end)" << endl;
    while(cin>>str)
        svec.push_back(str);
    char **parr=new char *[svec.size()];

    size_t ix=0;
    for(vector<string>::iterator iter=svec.begin();
            iter!=svec.end();++iter,++ix){
        char *p=new char[(*iter).size()+1];
        strcpy(p,(*iter).c_str());
        parr[ix]=p;
    }
    cout << "Content of vector:" << endl;
    for(vector<string>::iterator iter2=svec.begin();
            iter2!=svec.end();++iter2)
        cout << *iter2 << endl;

    cout << "Content of character arrays:" << endl;
    for(ix=0;ix!=svec.size();++ix)
        cout << parr[ix] << endl;
    for(ix=0;ix!=svec.size();++ix)
        delete[] parr[ix];
    delete[] parr;
    return 0;
}
