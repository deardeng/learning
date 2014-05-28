#include<iostream>
using namespace std;
#include<vector>

double vectorSum(vector<double>::iterator begin,
        vector<double>::iterator end){
    double sum=0.0;
    while(begin!=end){
        sum+=*begin++;
    }
    return sum;
}

int main(){
    vector<double> dvec;

    cout << "Enter double type elements for vector:(Ctrl+D to end)" << endl;
    double dval;
    while(cin >> dval)
        dvec.push_back(dval);

    cout << "Summation of elements: " << vectorSum(dvec.begin(),dvec.end()) << endl;

    return 0;
}
