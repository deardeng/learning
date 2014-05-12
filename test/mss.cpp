#include<iostream>
using namespace std;
#include<string>
#include<ctime>
#include<fstream>

int main(int argc,char *argv[]){
    ifstream fin(argv[1]);
    char ch;
    for(;;){
        fin.get(ch);
        if(!fin)break;
        time_t t=time(NULL);
        while(t==time(NULL));

        cout << ch << flush;
    }
    fin.close();
}
