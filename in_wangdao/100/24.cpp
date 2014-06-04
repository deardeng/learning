#include <iostream>
using namespace std;
#include <cstring>

int fun(char *a);

int main(int argc, const char *argv[])
{
    char str[128];
    cout << "input a number string:";
    cin >> str;
    cout << "your input number is :" << fun(str) << endl;
    return 0;
}

int fun(char *a){
    int s=0,t;
    int i=0,j,n=strlen(a),k,s1;
    if(a[0]=='-')
        i++;
    for(j=i;j<n;j++){
        t=a[j]-'0';
        s1=10;
        for(k=j;k<n-1;k++)
            t*=s1;
        s+=t;
    }
    if(a[0]=='-')
        return -s;
    else
        return s;
}
