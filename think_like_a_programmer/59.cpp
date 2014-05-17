#include<iostream>
using namespace std;

int main(){
    int number;
    int positiveCount=0;
    int negativeCount=0;
    for(int i=1;i<=10;i++){
        cin >> number;
        if(number > 0)positiveCount++;
        if(number < 0)negativeCount++;
    }
    char response;
    cout << "Do you want the (P)ositive or (N)egative count?";
    cin >> response;
    if(response=='p')
        cout << "Positive count is " << positiveCount << "\n";
    if(response=='n')
        cout << "Negative count is " << negativeCount << "\n";
}
