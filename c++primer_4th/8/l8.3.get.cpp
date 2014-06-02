#include<iostream>
using namespace std;
#include<stdexcept>
#include<exception>
#include<string>
#include<fstream>
#include<sstream>
istream& get(istream& in){
    string ival;
    //int ival;

    while(in >> ival,!in.eof()){
        if(in.bad())
            throw runtime_error("IO stream error.");

        if(in.fail()){
            cerr << "bad data,try again";
            in.clear();
            in.ignore(200,' ');
            continue;
        }
        cout << ival << "*";
    }
    in.clear();
    return in;
}

int main(){
    ifstream in("1.txt");
    //string line;
    //cout << "Enter a line of text:" << endl;
    //getline(cin,line);
    //istringstream isstr(line);
    //get(isstr);
    get(in);
}
