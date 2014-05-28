#include<iostream>
using namespace std;

int rgcd(int v1,int v2){
    if(v2!=0)
        return rgcd(v2,v1%v2);
    return v1;
}

int main(){
    cout<< rgcd(4,3) << endl;
    cout<< rgcd(4,2) << endl;
}
