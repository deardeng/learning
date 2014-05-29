#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
using namespace std;
#include<string>

class Sales_item{
    public:
        istream& input(istream& in);
        ostream& output(ostream& out)const;
        double avg_price()const;
        bool same_isbn(const Sales_item &rhs)const{
            return isbn == rhs.isbn;
        }
        Sales_item():units_sold(0),revenue(0.0){}
        Sales_item add(Sales_item& other);
    private:
        string isbn;
        unsigned units_sold;
        double revenue;
};

#endif
