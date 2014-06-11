#include <iostream>
using namespace std;
#include <vector>

int main(int argc, const char *argv[])
{
    vector<int> iv;
    int some_val,num;
    cout << "input some numbers(Ctrl+D to end):" << endl;
    while(cin >> num)
        iv.push_back(num);
    for(vector<int>::iterator it=iv.begin();it!=iv.end();it++)
        cout << *it << ' ';
    cout << endl;
    cin.clear();
    cout << "input a number which you just input:";
    cin >> some_val;
    vector<int>::iterator iter=iv.begin();
    while(iter!=iv.begin()+iv.size()/2){
        if(*iter==some_val){
            iter=iv.insert(iter,2*some_val);
            iter+=2;
        }
        else
            ++iter;
    }
    for(vector<int>::iterator it=iv.begin();it!=iv.end();it++)
        cout << *it << ' ';
    cout << endl;
    return 0;
}
