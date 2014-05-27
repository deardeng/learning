#include<iostream>
using namespace std;

int power(int x,int y){
    int result=1;
    for(int loop=1;loop<=y;++loop)
        result *= x;
    return result;
}

int main(){
    int xval,yval;
    cout << "Enter two integers(the second one should be equal to or bigger than 0):" << endl;
    cin >> xval >> yval;
    if(yval < 0){
        cout << "The second integer should be equal to or bigger than 0 " << endl;
        return -1;
    }
    cout << "Result of raising " << xval << " to the power of " << yval << " is " << power(xval,yval) << endl;
    return 0;
}
