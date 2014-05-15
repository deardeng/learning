#include<iostream>
using namespace std;

int main(){
    const size_t arr_size = 8;
    int int_arr[arr_size] = {0,1,2,3,4,5,6,7};

    for(int *pbegin=int_arr,*pend=int_arr+arr_size;pbegin!=pend;++pbegin)
        *pbegin=0;
    return 0;
}
