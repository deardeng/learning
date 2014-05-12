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
    cout << endl << "Sum of each pair of counterpart elements in the vector:" << endl;
    vector<int>::size_type cnt=0;
    vector<int>::size_type cur;
    bool flag=false;
    for(vector<int>::size_type first=0,last=ivec.size()-1;first<last;++first,--last){
        cout << ivec[first]+ivec[last] << "\t";
        ++cnt;
        if(cnt%6==0)
            cout << endl;
        if(first+1==last-1){
            flag=true;
            cur=first+1;
        }
    }
    if(flag)
        cout << endl << "The center element is not beensummed " << "and its value is " << ivec[cur] << endl;
    return 0;
}
