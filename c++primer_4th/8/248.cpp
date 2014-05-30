#include<iostream>
using namespace std;
#include<stdexcept>
#include<exception>
#include<limits>

int main(){
    int ival;

    while(cin >> ival,!cin.eof()){
        if(cin.bad())
            throw runtime_error("IO stream corrupted");
        if(cin.fail()){
            cerr << "bad data,try again" << endl;
            //cin.clear(istream::failbit);
            cin.clear();
            cin.ignore(10,'\n');
            //cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
    }
    return 0;
}
