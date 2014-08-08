#include <iostream>
using namespace std;
#include <list>
#include <deque>
#include <string>

int main(){
    list<int> ilst;
    deque<int> evenDq,oddDq;
    int ival;
    cout << "Enter some integers(Ctrl+D to end):" << endl;
    while(cin >> ival)
        ilst.push_back(ival);
    for(list<int>::iterator iter=ilst.begin();iter!=ilst.end();++iter){
        if(*iter%2==0)
            evenDq.push_back(*iter);
        else
            oddDq.push_back(*iter);
    }
    cout << "deque1:";
    for(deque<int>::iterator it1=evenDq.begin();it1!=evenDq.end();it1++)
        cout << *it1 << ' ';
    cout << endl;
    cout << "deque2:";
    for(deque<int>::iterator it=oddDq.begin();it!=oddDq.end();it++)
        cout << *it << ' ';
    cout << endl;
}
