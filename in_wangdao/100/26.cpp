#include <iostream>
using namespace std;
#include <cmath>

double fun(double eps);

int main(){
    cout << "-----------------" << endl;
    cout << "input a num:" << endl;
    double x;
    cin >> x;
    cout << "the result:" << fun(x) << endl;
    cout << "-----------------" << endl;
}

double fun(double eps){
    double s;
    float n,t,pi;
    t=1;pi=0;n=1.0;s=1.0;
    while((fabs(s)>=eps)){
        cout << s << ' ';
        pi+=s;
        t=n/(2*n+1);
        s*=t;
        n++;
    }
    pi=pi*2;
    return pi;
}
