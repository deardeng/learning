#include<iostream>
using namespace std;
#include<vector>

int main(){
    const size_t arr_size=8;
    int int_arr[arr_size];
    cout << "Enter " << arr_size << " numbers:" << endl;
    for(size_t ix=0;ix!=arr_size;++ix)
        cin >> int_arr[ix];
    vector<int> ivec(int_arr,int_arr+arr_size);
    for(vector<int>::iterator it=ivec.begin();it!=ivec.end();it++)
        cout << *it << ' ';
    return 0;
}
