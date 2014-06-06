#include <iostream>
using namespace std;
#include <list>
#include <vector>

int main(){
    vector<int> a(10);
    cout << "input 10 nums to vector :" << endl;
    vector<int>::iterator vt;
    for(vt=a.begin();vt!=a.end();vt++){
        cin >> *vt;
    }
    list<int> lst(a.begin(),a.end());
    list<int>::iterator lter1 = lst.begin(),lter2 = lst.end();

    while(lter2!=lter1)
        cout << *(--lter2)<< ' ';
    cout << endl;
}
