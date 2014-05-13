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
    cout << endl << "Sum of each pair of adjacent elements int vector:" << endl;
    vector<int>::size_type cnt=0;
    for(vector<int>::iterator iter=ivec.begin();iter<ivec.end()-1;iter<ivec.end()-1,iter=iter+2){
        cout << *iter+*(iter+1) << "\t";
        ++cnt;
        if(cnt%3==2)
            cout << endl;
    }
    if(ivec.size()%2!=0)
        cout << endl << "The last element is not been summed" << "and its value is " << *(ivec.end()-1) << endl;
    else 
        cout << endl;
    return 0;
}
