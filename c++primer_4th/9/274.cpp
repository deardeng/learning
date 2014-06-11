#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <list>

int main(int argc, const char *argv[])
{
    vector<string> svec;
    list<string> slist;
    list<string> lst;
    string spouse("Beth");
    string spous("deardeng");
    slist.insert(slist.begin(),spouse);
    slist.insert(slist.end(),spous);
    string sarray[4]={"quasi","simba","frollo","scar"};
    slist.insert(slist.end(),sarray,sarray+4);
    list<string>::iterator slist_iter=slist.begin();
    slist.insert(slist_iter,sarray+2,sarray+4);
    svec.insert(svec.end(),spouse);
    svec.insert(svec.begin(),spous);
    svec.insert(svec.end(),10,"Anna");
    for(vector<string>::iterator sit=svec.begin();sit!=svec.end();sit++){
        cout << *sit << ' ';
    }
    cout << endl;
    for(list<string>::iterator lit=slist.begin();lit!=slist.end();lit++){
        cout << *lit << ' ';
    }
    cout << endl;
    string word;
    list<string>::iterator iter=lst.begin();
    while(cin>>word)
        iter=lst.insert(iter,word);
    for(list<string>::iterator lit=lst.begin();lit!=lst.end();lit++){
        cout << *lit << ' ';
    }
    return 0;
}
