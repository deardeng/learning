#include<iostream>
using namespace std;

int main(){
    string rsp;
    do{
        cout << "please enter two values: ";
        int val1,val2;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
            << " = " << val1+val2 << "\n\n"
            << "More? [yes][no] ";
        cin >> rsp;
    }while(!rsp.empty()&&rsp[0]!='n');
    return 0;
}
