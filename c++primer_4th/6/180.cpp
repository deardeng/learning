#include<iostream>
using namespace std;
#include<string>
#include<vector>

int main(){
    vector<string> svec(3);
    for(vector<string>::size_type ind=0;ind!=svec.size();++ind){
        cin >> svec[ind];
    }
    /*one*/
    //for(vector<string>::size_type ind=0;ind!=svec.size();++ind){
    //    cout << svec[ind];
    //    if(ind+1 != svec.size())
    //        cout << ' ';
    //}
    
    /*two*/
    //for(vector<string> :: iterator iter = svec.begin();iter != svec.end();
    //        iter++){
    //    cout << *iter;
    //    if( iter+1 != svec.end())
    //        cout << '|';
    //}
    
    /*three*/
    for(vector<string> :: iterator iter = svec.begin();iter != svec.end();
            iter++)
        cout << *iter << '|';
    cout << "\b ";
        
    cout << endl;
}
