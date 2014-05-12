#include<iostream>
using namespace std;

class Array{
    char *p;
    int len;
    public:
    Array(int n):len(0),p(NULL){
        resize(n);
    }
    void resize(int n){
        char *q=new char[n];
        int min=(n<len?n:len);
        if(p!=NULL){
            for(int i=0;i<min;i++)
                q[i]=p[i];
            delete[] p;
        }
        p=q;
        for(int i=min;i<n;i++)
            p[i]='\0';
        len=n;
    }
    void set(int index,char value){
        if(index<0||index>=len){
            cout << "ERR:" << index << endl;
            return ;
        }
        p[index]=value;
    }
    char get(int index){
        if(index<0||index>=len){
            cout << "ERR:" << index << endl;
            return '!';
        }
        return p[index];
    }
    int size(){
        return len;
    }
    ~Array(){
        if(p!=NULL){
            delete[] p;
            p=NULL;
        }
    }
};
int main(){
    Array a1(100);
    cout << "input chars(end by '$')";
    for(int i=0;;i++){
        char ch;
        cin>>ch;
        if(ch=='$')
            break;
        else if(i+1<a1.size())
            a1.resize(i+10);
        a1.set(i,ch);
    }
    for(int i=0;i<a1.size();i++)
        cout << a1.get(i);
    cout << endl;
}
