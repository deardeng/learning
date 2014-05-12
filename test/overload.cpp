#include<iostream>
using namespace std;

class Array{
    char *p;
    int len;
    public:
    Array(int n):len(n),p(new char[n]){
    }
    int size(){
        return len;
    }
    ~Array(){
        delete[] p;
    }
    void fill(char start,int skip){
        for(int i=0;i<len;i++)
            p[i]=start+i*skip;
    }
    void show(){
        for(int i=0;i<len;i++)
            cout << p[i];
        cout << endl;
    }
    Array(const Array& o):len(o.len){
        p=new char[len];
        for(int i=0;i<len;i++)
            p[i]=o.p[i];
    }
};
int main(){
    Array a1(10);
    a1.fill('a',1);
    a1.show();
    Array a2(a1);
    a2.fill('A',1);
    a2.show();
    a1.show();
}
