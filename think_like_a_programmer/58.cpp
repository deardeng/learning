#include<iostream>
using namespace std;
int doubleDigitValue(int digit);

int main(){
    char digit;
    int checksum=0;
    int position=1;
    cout << "Enter a six-digit number: ";
    digit=cin.get();
    while(digit!=10){
        if(position%2==0)checksum+=digit-'0';
        else checksum+=2*(digit-'0');
        digit=cin.get();
        position++;
    }
    cout << "Checksum is " << checksum << ".\n";
    if(checksum%10==0){
        cout << "Checksum is divisible by 10. Valid.\n";
    }else{
        cout << "Checksum is not divisible by 10.Invalid.\n";
    }
    return 0;
}

int doubleDigitValue(int digit){
    int doubledDigit = digit*2;
    int sum;
    if(doubledDigit > 10)sum = 1+doubledDigit%10;
    else sum = doubledDigit;
    return sum;
}
