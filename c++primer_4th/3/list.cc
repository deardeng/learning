#include<iostream>
using namespace std;
typedef int T;
class List{
    struct Node{
        T data;
        Node* next;
        Node(const T &t=T()):data(t),next(NULL){}
    };
    Node *head;
    public:
    List():head(NULL){}
    void clear(){
        while(head){
            Node *q=head->next;
            delete head;
            head = q;
        }
    }
    ~List(){clear();}
    void insert_front(const T& t){
        Node *p=new Node(t);
        p->next=head;
        head=p;
    }
    void insert_back(const T& t){
        Node *p=new Node(t);
        if(head==NULL)
            head=p;
        else
            getPointer(size()-1)->next=p;
    }
    void travel(){
        Node *p=head;
        while(p){
            cout << p->data << ' ';
            p=p->next;
        }
        cout << endl;
    }
    int size(){
        Node *p=head;
        int cnt=0;
        while(p){
            cnt++;
            p=p->next;
        }
        return cnt;
    }
    T getHead(){
        if(!head)
            throw "no head";
        return head->data;
    }
    T getTail(){
        if(!head)
            throw "no tail";
        Node *p=head;
        while(p->next)
            p=p->next;
        return p->data;
    }
    bool empty(){
        return !head;
    }
    int find(const T& t){
        int pos=0;
        Node *p=head;
        while(p){
            if(p->data==t)
                return pos;
            p=p->next;
            pos++;
        }
        return -1;
    }
    bool update(const T& o,const T& n){
        int pos=find(o);
        if(pos==-1)
            return false;
        Node *p=getPointer(pos);
        p->data=n;
        return true;
    }
    private:
    Node* getPointer(int pos){
        Node *p=head;
        for(int i=0;i<pos;i++)
            p=p->next;
        return p;
    }
    public:
    bool erase(const T& t){
        int pos=find(t);
        if(pos==-1)
            return false;
        if(pos==0){
            Node* q=head->next;
            delete head;
            head = q;
        }
        else{
            Node *pre = getPointer(pos-1);
            Node *cur= pre->next;
            pre->next = cur->next;
            delete cur;
        }
        return true;
    }
};
int main(){
    List obj;
    obj.insert_front(1);
    obj.insert_front(2);
    obj.insert_front(3);
    obj.insert_front(4);
    obj.insert_front(5);
    cout << "size:" << obj.size() << endl;
    cout << "find 3:" << obj.find(3) << endl;
    cout << "find 8:" << obj.find(8) << endl;
    cout << "update:" << obj.update(4,100) << endl;
    obj.travel();
    obj.erase(3);
    obj.erase(5);
    obj.erase(1);
    obj.insert_back(23);
    obj.travel();
}
