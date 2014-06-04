#include<iostream>
using namespace std;
#include<cstring>

void fun(char *s);

int main(int argc, const char *argv[])
{
    char str[128];
    cout << "input a sentence:" ;
    cin >> str;
    fun(str);
    cout << "ater change:" << str << endl;
    return 0;
}

void fun(char *s){
    int len=strlen(s);
    char ch;
    for(int i=0;i<len/2;i++){
        ch=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=ch;
    }
}
