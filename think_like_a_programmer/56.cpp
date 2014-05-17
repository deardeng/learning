#include<iostream>
using namespace std;

int main(){
    char digit;
    int checksum=0;
    cout << "Enter a six-digit number: ";
    for(int position=1;position<=6;position++){
        cin >> digit;
        checksum+=digit-'0';
    }
    cout << "Checksum is " << checksum << ".\n";
    if(checksum%10==0){
        cout << "Checksum is divisible by 10. Valid.\n";
    }else{
        cout << "Checksum is not divisible by 10.Invalid.\n";
    }
    return 0;
}
