#include<iostream>
using namespace std;

int main(){
    char currCh,preCh='\0';

    int ffCnt=0,flCnt=0,fiCnt=0;
    while(cin >> currCh){
        if(preCh=='f')
            switch(currCh){
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }
        preCh=currCh;
    }
    cout << "Number of \"ff\": \t" << ffCnt << endl;
    cout << "Number of \"fl\": \t" << flCnt << endl;
    cout << "Number of \"fi\": \t" << fiCnt << endl;

    return 0;
}
