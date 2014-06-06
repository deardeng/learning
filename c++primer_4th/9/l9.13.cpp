#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <string>

vector<int>::iterator findInt(vector<int>::iterator beg,vector<int>::iterator end,int ival){
    while(beg!=end){
        if(*beg==ival)
            break;
        else
            ++beg;
    }
    if(beg!=end)
        return beg;
    else
        return end;
}

int main(){
    vector<int> a(10);
    cout << "input 10 nums to vector :" << endl;
    vector<int>::iterator vt;
    for(vt=a.begin();vt!=a.end();vt++){
        cin >> *vt;
    }
    cout << "what number you want to find ,input it:" << endl;
    int b;
    cin >> b;
    vector<int>::iterator l=findInt(a.begin(),a.end(),b);
    cout << *l << endl;
}
