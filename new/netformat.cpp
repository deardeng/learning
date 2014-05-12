#include<iostream>
using namespace std;
#include<netinet/in.h>
#include<iomanip>

int main(){
    short s=1;
    long l=1;
    cout.fill('0');
    cout << hex;
    cout << setw(4) << s << endl;
    cout << setw(8) << l << endl;
    cout << "-----------------" << endl;
    s=htons(s);
    l=htonl(l);
    cout << setw(4) << s << endl;
    cout << setw(8) << l << endl;
    cout << "-----------------" << endl;
    s=ntohs(s);
    l=ntohl(l);
    cout << setw(4) << s << endl;
    cout << setw(8) << l << endl;
}
