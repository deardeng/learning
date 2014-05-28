#include<iostream>
using namespace std;

int factorial(int val){
    int result=1;
    for(int i=1;i<=val;++i)
        result *= i;
    return result;
}

int main(){
    cout << factorial(5) << endl;
}
