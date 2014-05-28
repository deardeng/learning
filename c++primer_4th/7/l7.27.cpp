#include<iostream>
using namespace std;

int fac(int x){
    static int result = 1;
    result *= x;
    return result;
}

int main(){
    int upLmt;
    cout << "Enter value of upper limit: " << endl;
    cin >> upLmt;

    for(int i=1;i<=upLmt;++i)
        cout << i << "!= " << fac(i) << endl;

    return 0;
}
