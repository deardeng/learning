#include<iostream>
using namespace std;

void fun(char *a,char *b,int n);

int main(){
    char str1[128],str2[128];
    int index;
    cout << "input a str" << endl;
    cin >> str1;
    cout << "input the index that you want to delete albat" << endl;
    cin >> index;
    fun(str1,str2,index);
    cout << "the result of your change:" ;
    cout << str2 << endl;
}

void fun(char *a,char *b,int n){
    int i=0;
    for(char *p=a;*p!='\0';p++,i++){
        if(i==n)
            continue;
        *b=*p;
        b++;
    }
}
