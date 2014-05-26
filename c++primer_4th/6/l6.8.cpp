#include<iostream>
using namespace std;

int main(){
    char ch;

    int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0,spaceCnt=0,tabCnt=0,newlineCnt=0;
    while(cin.get(ch)){
        switch(ch){
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
        }
    }
    cout << "Number of vowel a: \t" << aCnt << endl;
    cout << "Number of vowel e: \t" << eCnt << endl;
    cout << "Number of vowel i: \t" << iCnt << endl;
    cout << "Number of vowel o: \t" << oCnt << endl;
    cout << "Number of vowel u: \t" << uCnt << endl;
    cout << "Number of space character: \t" << spaceCnt << endl;
    cout << "Number of Tab character: \t" << tabCnt << endl;
    cout << "Number of newlineCnt: \t" << newlineCnt << endl;

    return 0;
}
