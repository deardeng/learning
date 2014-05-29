#include"l7.31.sales_item.h"
#include<iostream>
using namespace std;

int main(){
    Sales_item total,trans;
    cout << "Enter some transactions(Ctrl+D to end):" << endl;
    if(total.input(cin)){
        while(trans.input(cin))
            if(total.same_isbn(trans))
                total.add(trans);
            else{
                total.output(cout) << endl;
                total = trans;
            }
        total.output(cout) << endl;
    }
    else
    {
        cout << "No data?!" << endl;
        return -1;
    }
    return 0;
}
