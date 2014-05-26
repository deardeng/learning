#include<iostream>
using namespace std;

int main(){
    do{
        int v1,v2;
        cout << "Please enter two numbers to sum:";
        cin >> v1 >> v2;
        if(cin)
            cout << "Sum is: " << v1+v2 << endl;
    }while(cin);
}
