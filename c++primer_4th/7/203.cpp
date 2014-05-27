#include<iostream>
using namespace std;
#include<vector>

vector<int>::const_iterator find_val(vector<int>::const_iterator beg,vector<int>::const_iterator end,int value,vector<int>::size_type &occurs){
    vector<int>::const_iterator res_iter = end;
    occurs=0;
    for(;beg!=end;++beg)
        if(*beg==value){
            if(res_iter==end)
                res_iter=beg;
            ++occurs;
        }
    return res_iter;
}

int main(){
    vector<int> ivec(10,0); 
    vector<int>::const_iterator it;
    vector<int>::size_type ctr;
    it=find_val(ivec.begin(),ivec.end(),10,ctr);
    cout << *it << ' ' << ctr << endl;
    return 0;
}
