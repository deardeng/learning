#include<iostream>
using namespace std;

int main(){
    char digit;
    cout << "Enter a one-digit number:";
    digit=cin.get();
    int sum=digit-'0';
    cout << "Is the sum of digits " << sum << "?\n";
    return 0;
}
