#include<iostream>
using namespace std;
#include<string>
#include<cctype>

int main(){
    string currWord,preWord;
    cout << "Enter some words:(Ctrl+D to end)" << endl;
    while(cin >> currWord){
#ifndef NDEBUG
        cout << currWord << " ";
#endif
        //if(!isupper(currWord[0]))
        //    continue;
        if(currWord==preWord && isupper(currWord[0]))
            break;
        else
            preWord = currWord;
    }
    if(currWord == preWord && !currWord.empty())
        cout << "The repeated word: " << currWord << endl;
    else
        cout << "There is no repeated word that has initial capital."
            << endl;
    return 0;
}
