#include <iostream>
using namespace std;
#include <vector>

int main(int argc, const char *argv[])
{
    //vector<int> v(10,10);
    vector<int> v(10);
    //v.push_back(10);
    //v.push_back(20);
    for(vector<int>::iterator vter=v.begin();vter!=v.end();vter++)
        cout << *vter << ' ';
    cout << endl;
    vector<int>::iterator first=v.begin(),last=v.end();//Error
    //while(first!=last){
    //    first=v.insert(++first,42);
    //    ++first;
    //}

    while(first!=v.end()){
        first=v.insert(++first,42);
        ++first;
    }
    for(vector<int>::iterator vter=v.begin();vter!=v.end();vter++)
        cout << *vter << ' ';
    cout << endl;
    return 0;
}
