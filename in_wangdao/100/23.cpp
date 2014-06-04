#include <iostream>
using namespace std;
#include <cstring>
#include <string>

int fun(char *s);

int main(int argc, const char *argv[])
{
    char str[128];
    cout << "input a sentence:";
    cin >> str;
    string s= fun(str)?"yes":"no";
    cout << "judge the sentence is or isn't a huiwen : " << s << endl;
    return 0;
}

int fun(char *s){
    int len=strlen(s);
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])
            return 0;
    }
    return 1;
}
