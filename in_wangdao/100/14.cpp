#include<iostream>
using namespace std;

const int M=3;
const int N=4;

int fun(int a[][N]);

int main(){
    int a[M][N];
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> a[i][j];
    cout << "the vector circumambient elements average is :" << fun(a) << endl;
}

int fun(int a[][N]){
    int all=0;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            if(i==0||j==N-1||j==0||i==M-1){
                all+=a[i][j];
            }
    return all;
}
