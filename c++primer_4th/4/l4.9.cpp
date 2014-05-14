#include<iostream>
using namespace std;
int main(){
    const int array_size=10;
    int ia[array_size];
    for(size_t ix=0;ix!=array_size;++ix)
        ia[ix]=ix+1;
    return 0;
}
