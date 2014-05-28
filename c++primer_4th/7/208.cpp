#include<iostream>
using namespace std;

void printValues(int (&arr)[10]){
    for(size_t i=0;i!=10;++i){
        cout << arr[i];
        if(i!=9)
            cout << '*';
    }
    cout << endl;
}

int main(){
    int k[10]={0,1,2,3,4,5,6,7,8,9};
    printValues(k);
    return 0;
}
