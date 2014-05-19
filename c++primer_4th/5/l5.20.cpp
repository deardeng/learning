#include<iostream>
using namespace std;
int main(){
    int val1,val2;
    
    cout << "Enter two integers:" << endl;
    cin >> val1 >> val2;

    cout << "The smaller one is " << (val1 < val2?val1:val2) << endl;
    return 0;
}
