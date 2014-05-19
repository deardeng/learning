#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> ivec;
    int ival;

    cout << "Enter numbers:(Ctrl+D to end)" << endl;
    while(cin>>ival)
        ivec.push_back(ival);
    int *parr=new int[ivec.size()];
    size_t ix=0;
    for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter,++ix)
        parr[ix]=*iter;
    for(ix=0;ix<ivec.size();ix++)
        cout << parr[ix] << ' ';
    cout << endl;
    delete[] parr;
    return 0;
}
