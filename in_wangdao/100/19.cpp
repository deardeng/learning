#include <iostream>
using namespace std;
#include <cstring>

void fun(char *s,char ch);

int main(int argc, const char *argv[])
{
    char str[128];
    cout << "input a sentence:";
    cin >> str;
    char ch;
    cout << "input a albat which you what to delete:" << endl;
    cin >> ch;
    fun(str,ch);
    cout << "after delete:";
    cout << str << endl;
    return 0;
}

//void fun(char *s,char ch){
//    char *p=s,*q=s;
//    char sh;
//    int len=strlen(s);
//    for(;*p!='\0';p++,q++){
//        if(*p==ch){
//            while(*p!='\0'){
//                *q++=*++p;
//            }
//            *p='\0';
//        }
//    }
//}

void fun(char str[],char ch){
    int i=0;
    char *p;
    p=str;
    while(*p){
        if(*p!=ch){
            str[i]=*p;
            i++;
        }
        p++;
    }
    str[i]='\0';
}
