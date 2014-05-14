#include<iostream>
using namespace std;

int main(){
    const size_t array_size=10;
    int ia1[]={0,1,2,3,4,5,6,7,8,9};
    int ia2[array_size];
    for(size_t ix=0;ix!=array_size;++ix)
        ia2[ix]=ia1[ix];
    return 0;
}
