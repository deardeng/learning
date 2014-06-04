#include <iostream>
using namespace std;
#include <cstring>
void fun(char *s);

int main(int argc, const char *argv[])
{
    char str[128];
    cout << "input a 7 albat string:";
    cin >> str;
    fun(str);
    cout << "after change:" << str << endl;
    return 0;
}

void fun(char *s){
    int ch;
    for(int i=1;i<6;i++)
        for(int j=1;j<6;j++)
            if(s[i]>=s[j]){
                ch=s[i];
                s[i]=s[j];
                s[j]=ch;
            }
}
