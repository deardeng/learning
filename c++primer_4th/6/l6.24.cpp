#include<iostream>
using namespace std;
#include<bitset>
#include<exception>

int main(){
    bitset<100> bs;

    for(size_t ix=0;ix!=bs.size();++ix)
        bs[ix]=1;

    try{
        bs.to_ulong();
    }catch(runtime_error err){
        cout << err.what() << endl;
    }
    return 0;
}
