#include<iostream>
using namespace std;

const int N=4;
const int M=3;

int fun(int a[M][N],int pp[]);

int main(){
    int a[N][N];
    int p[N];
    int nnum;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> a[i][j];
    nnum=fun(a,p);
    cout << "every col's max element are:";
    for(int i=0;i<N;i++)
        cout << p[i] << ' ';
    cout << endl;
}

int fun(int a[M][N],int *pp){
    int max=0,n=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(max<a[j][i])
                max=a[j][i];
        pp[n++]=max;
    }
    return n;
}
