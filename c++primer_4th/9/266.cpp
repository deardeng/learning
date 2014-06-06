#include <iostream>
using namespace std;
#include <string>
#include <list>

int main(){
    char *words[]={"stately","plump","buck","mulligan"};
    size_t words_size=sizeof(words)/sizeof(char *);
    list<string> words2(words,words+words_size);
    for(list<string>::iterator lvec=words2.begin();lvec!=words2.end();lvec++)
        cout << *lvec << endl;
    cout << "============================" << endl;
    const list<int>::size_type list_size=64;
    list<string> slist(list_size,"eh?");
    for(list<string>::iterator lvec=slist.begin();lvec!=slist.end();lvec++)
        cout << *lvec << endl;
    cout << "============================" << endl;
}
