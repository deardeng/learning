#include<iostream>
using namespace std;

const int N=3;

void fun(int a[][N]);

int main(){
    int a[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> a[i][j];
    fun(a);
    cout << "after change:" << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void fun(int a[][N]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(j<i)
                a[i][j]=0;
}
