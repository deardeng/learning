#include <iostream>
using namespace std;

float fun(float h);

int main(){
    float h;
    cout << "input a num (x.xxx)" ;
    cin >> h;
    cout << "after change :" << fun(h) << endl;
}

float fun(float h){
    long t;
    float s;
    h=h*1000;
    t=(h+5)/10;
    s=(float)t/100.0;
    return s;
}
