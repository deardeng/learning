#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> ivec;
    int ival;
    cout << "Enter numbers:(Ctrl+D to end)" << endl;
    while(cin>>ival)
        ivec.push_back(ival);
    int *pia=new int[ivec.size()];
    int *tp=pia;
    cout << endl;
    for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter,++tp)
        *tp=*iter;
    for(int i=0;i!=ivec.size();i++)
        cout << *(pia+i) << ' ';
    delete [] pia;
    return 0;
}
