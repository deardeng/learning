#include<iostream>
using namespace std;
#include<string>

int main(){
    string str1,str2,str3;
    do{
        cout << "Enter two strings:" << endl;
        cin >> str1 >> str2;
        if(str1 < str2)
            cout << "The first string is smaller than the second one."
                << endl;
        else if(str1 == str2)
            cout << "Two strings are equal." << endl;
        else
            cout << "The second string is smaller than the first one."
                << endl;

        cout << "Continue?(y-yes,n-no)" << endl;
        cin >> str3;
    }while(str3[0] != 'n' && str3[0] != 'N');

    return 0;
}
