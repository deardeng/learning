#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
using namespace std;
#include<cstddef>
template< typename T>
class List{
    struct Node{
        T data;
        Node* next;
        Node(const T& d=T()):data(d),next(0){}//零初始化
    };
    Node* head;//头指针，用来保存头节点的地址
    int len;
    public:
    List():head(NULL),len(0){}
    void push_front(const T& d);//前插
    List& push_back(const T& d);//尾插
    int size()const;
    Node*& getptr(int pos);//找链表中指向指定位置的指针
    void insert(const T& d,int pos);//在任意位置插入
    void travel_user()const;//遍历
    void clear();//清空这个链表
    ~List();
    void erase(int pos);//有效位置为0~size()-1
    void remove(const T& d);
    int find(const T& d)const;
    void set(int pos,const T& d);
    bool empty()const{return head == 0;}
    const T& front()const{if(empty())throw"空";return head->data;}
    const T& back()const;
    void travel_student()const;
};


template < typename T>
void List<T>::push_front(const T&d){
    insert(d,0);
}
template < typename T>
List<T>& List<T>::push_back(const T& d){//尾插
    insert(d,size());
    return *this;
}
template < typename T>
int List<T>::size()const{
    return len;
}
template < typename T>
typename List<T>::Node*& List<T>::getptr(int pos){//找链表中指向指定位置的指针
    if(pos<0||pos>size()) pos = 0;
    if(pos == 0)return head;
    Node* p = head;
    for(int i=1;i<pos;i++)
        p = p->next;
    return (*p).next;
    //1:return (*p).next;
    //2:p=p->next:return (*p).next;
    //3:p=p->next:p=p->next;return (*p).next;
}
template < typename T>
void List<T>::insert(const T& d,int pos){//在任意位置插入
    Node*& pn = getptr(pos);
    Node* p = new Node(d);
    p->next = pn;
    pn = p;
    len++;
}
template < typename T>
void List<T>::travel_user()const{//遍历
    Node* p = head;
    while(p!=NULL){
        cout << p->data->usr_name << ' ';
        cout << p->data->usr_pwd<< ' ';
        cout << p->data->usr_role<< ' ';
        cout << endl;
        p = p->next;
    }
    cout << endl;
}
template < typename T>
void List<T>::travel_student()const{//遍历
    Node* p = head;
    while(p!=NULL){
        cout << p->data->usr_id << ' ';
        cout << p->data->usr_name<< ' ';
        cout << p->data->usr_course_id<< ' ';
        cout << p->data->usr_course_score<< ' ';
        cout << endl;
        p = p->next;
    }
    cout << endl;
}
template < typename T>
void List<T>::clear(){//清空这个链表
    while(head != NULL){
        Node* p = head->next;
        //	cout << "delete" << head << endl;
        delete head;
        head = p;
    }
    len = 0;
}
template < typename T>
List<T>::~List<T>(){
    //cout << this << "*********" << head << endl;
    clear();
}
template < typename T>
void List<T>::erase(int pos){//有效位置为0~size()-1
    if(pos<0||pos>=size())return;
    Node*& pn = getptr(pos);
    Node* p = pn;
    pn = pn->next;
    delete p;
    --len;
}
template < typename T>
void List<T>::remove(const T& d){
    int pos;
    while((pos = find(d))!=-1)
        erase(pos);
}
template < typename T>
int List<T>::find(const T& d)const{
    Node* p = head;
    int pos=0;
    while(p){
        if(p->data==d)return pos;
        p = p->next;++pos;
    }
    return -1;
}
template < typename T>
void List<T>::set(int pos,const T& d){
    if(pos<0||pos>=size())return;
    getptr(pos)->data = d;
}
template < typename T>
const T& List<T>::back()const{
    if(empty())throw"NULL";
    Node* p=head;
    while(p!=NULL&&p->next!=NULL){
        p=p->next;
    }
    return p->data;
}

#endif
