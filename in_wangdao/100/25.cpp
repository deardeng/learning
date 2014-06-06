#include <iostream>
using namespace std;

char* fun(char *s,char *t);

int main(int argc, const char *argv[])
{
    char str1[128];
    char str2[128];
    cout << "input first number string:";
    cin >> str1;
    cout << "input second number string:";
    cin >> str2;
    string a=fun(str1,str2);
    cout << "the longger is:" << a << endl;
    return 0;
}

char* fun(char *s,char *t){
    char *str1,*str2;
    str1=s;
    str2=t;
    while(*str1!='\0'&&*str2!='\0'){
        str1++;
        str2++;
    }
    if(*str2=='\0')
        return s;
    else
        return t;

}
