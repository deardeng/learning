#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> ivec1,ivec2;
    int ival;

    cout << "Enter elements for the first vector :(32767 to end)"
        << endl;
    cin >> ival;
    while(ival != 32767){
        ivec1.push_back(ival);
        cin >> ival;
    }

    cout << "Enter elements for the second vector :(32767 to end)"
        << endl;
    cin >> ival;
    while(ival != 32767){
        ivec2.push_back(ival);
        cin >> ival;
    }

    vector<int>::size_type size1,size2;
    size1=ivec1.size();
    size2=ivec2.size();
    bool result = true;
    for(vector<int>::size_type ix=0;ix != (size1>size2?size2:size1);
            ++ix)
        if(ivec1[ix]!=ivec2[ix]){
            result = false;
            break;
        }

    if(result){
        if(size1<size2)
            cout << "The first vector is prefix of the second one."
                << endl;
        else if(size1==size2)
            cout << "Two vectors are equal." << endl;
        else
            cout << "The second vector is prefix of the first one."
                << endl;
    }
    else
        cout << "No vector is prefix of the other one." << endl;
    return 0;
}
