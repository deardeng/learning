#include<iostream>
using namespace std;
#include<string>

int main(){
    string currWord,preWord;
    cout << "Enter some words:(Ctrl+D to end)" << endl;
    while(cin >> currWord){
        if(currWord == preWord && isupper(currWord[0]))
            break;
        else
            preWord = currWord;
    }

    if(currWord == preWord && !currWord.empty())
        cout << "The repeated word: " << currWord << endl;
    else
        cout << "There is no repeated word." << endl;

    return 0;
}
