#include<iostream>
using namespace std;
#include<cmath>

float fun();

int main(){
    int x;
    cout << "input the x to get the function(x=cos(x)) root" << endl;
    cin >> x;
    cout << "the function's root is " << fun() << endl;
}

float fun(){
    float x0,x1;
    x1=0.0;
    do{
        x0=x1;
        x1=cos(x0);
        if(abs(x0-x1)<0.000001)
            return x1;
        else
            continue;
    }while(1);
}
