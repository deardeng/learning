#include<iostream>
using namespace std;
#include<stdexcept>
#include<exception>
#include<string>

istream& get(istream& in){
    int ival;
    
    while(in >> ival,!in.eof()){
        if(in.bad())
            throw runtime_error("IO stream error.");

        if(in.fail()){
            cerr << "bad data,try again";
            in.clear();
            in.ignore(200,' ');
            continue;
        }

        cout << ival << " ";
    }
    in.clear();
    return in;
}

