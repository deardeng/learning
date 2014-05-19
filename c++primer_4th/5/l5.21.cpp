#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> ivec(20,4);
    for(vector<int>::iterator iter=ivec.begin();
            iter!=ivec.end();++iter){
        *iter=(*iter%2==0?*iter:*iter*2);
    }
    for(vector<int>::iterator iter=ivec.begin();
            iter!=ivec.end();++iter)
        cout << *iter << endl;
    return 0;
}
