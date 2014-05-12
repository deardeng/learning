#include<iostream>
using namespace std;
#include<cstring>
int main(){
    char *p="Hello";
    for(int i=0;i<strlen(p);i++)
        cout << *(p+i) << endl;
    return 0;
}
