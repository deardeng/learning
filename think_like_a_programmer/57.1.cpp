#include<iostream>
using namespace std;

int main(){
    cout << "Enter a number: ";
    char digit;
    while(true){
        digit=cin.get();
        cout << int(digit) << " ";
    }
}
