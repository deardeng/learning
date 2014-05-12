#include<iostream>
using namespace std;

int main(){
    int base,exponent;
    long result=1;
    cout << "Enter base and exponent:" << endl;
    cin >> base >> exponent;
    if(exponent < 0){
        cout << "Exponent can't be smaller than 0" << endl;
        return -1;
    }
    if(exponent > 0){
        for(int cnt=1;cnt <= exponent;++cnt)
            result *= base;
    }
    cout << base << "raised to the power of" << exponent << ":" << result << endl;
    return 0;
}
