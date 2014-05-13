#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ivec;
    int ival;
    cout << "Enter numbers(Ctrl+D to end):" << endl;
    while(cin >> ival)
        ivec.push_back(ival);
    if(ivec.size()==0){
        cout << "No element?!" << endl;
        return -1;
    }
    cout << "Sum of each pair of counterpart elements in the vector:" << endl;
    vector<int>::size_type cnt=0;
    vector<int>::iterator first,last;
    for(first=ivec.begin(),last=ivec.end()-1;first<last;++first,--last){
        cout << *first+*last << "\t";
        ++cnt;
        if(cnt%6==0)
            cout << endl;
    }
    cout << endl;
    if(first==last)
        cout << endl << "The center element is not been summed" << "and its value is " << *first << endl;
    return 0;
}
