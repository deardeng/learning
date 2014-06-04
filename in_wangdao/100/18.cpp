#include<iostream>
using namespace std;

const int N=3;

void fun(int a[][N]);

int main(){
    int a[N][N];
    cout << "input 9 numbers:" << endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> a[i][j];
    cout << "before change:" << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << "after change:" << endl;
    fun(a);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void fun(int a[][N]){
    int temp;
    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++){
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
}
