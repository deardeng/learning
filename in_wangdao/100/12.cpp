#include<iostream>
using namespace std;

const int N=3;

double fun(int a[][N]);

int main(){
    int a[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> a[i][j];
    cout << "the vector circumambient elements average is :" << fun(a) << endl;
}

double fun(int a[][N]){
    double all=0;
    int nnum=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i==0||j==N-1||j==0||i==N-1){
                all+=a[i][j];
                nnum++;
            }
    return all/nnum;
}
