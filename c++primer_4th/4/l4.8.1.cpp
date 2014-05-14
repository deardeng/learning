#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> ivec1,ivec2;
    int ival;
    cout << "Enter numbers for vector1(-1 to end);" << endl;
    cin >> ival;
    while(ival!=-1){
        ivec1.push_back(ival);
        cin >> ival;
    }
    cout << "Enter numbers for vector2(-1 to end);" << endl;
    cin >> ival;
    while(ival!=-1){
        ivec2.push_back(ival);
        cin >> ival;
    }

    if(ivec1.size()!=ivec2.size())
        cout << "Vector1 is not equal to Vector2." << endl;
    else if(ivec1.size()==0)
        cout << "Vector1 is equal to Vector2." << endl;
    else{
        vector<int>::iterator iter1,iter2;
        iter1=ivec1.begin();
        iter2=ivec2.begin();
        while(*iter1==*iter2&&iter1!=ivec1.end()&&iter2!=ivec2.end()){
            ++iter1;
            ++iter2;
        }
        if(iter1==ivec1.end())
            cout << "Vector1 is equal to Vector2." << endl;
        else
            cout << "Vector1 is not equal to vector2." << endl;
    }
    return 0;
}
