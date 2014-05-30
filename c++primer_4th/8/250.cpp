#include<iostream>
using namespace std;

int main(){
    cout << "hi!" << flush;
    cout << "hi!" << ends;
    cout << "hi!" << endl;

    cout << unitbuf << "first" << "second" << nounitbuf;
}
