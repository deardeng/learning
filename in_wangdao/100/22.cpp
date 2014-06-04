#include <iostream>
using namespace std;
#include <new>

typedef struct Stu_{
    Stu_ *next;
    int score;
}node;

typedef node list;

double fun(list *root);

void createlist(node *n);

void showlist(node *n);

int main(int argc, const char *argv[])
{
    node root;
    root.next=NULL;
    cout << "input 10 students score:" << endl;
    for(int i=0;i<10;i++){
        createlist(&root);
    }
    showlist(&root);
    cout << "the biggist score of the 10 students is:" << fun(&root) << endl;
    return 0;
}

void createlist(node *n){
    int score;
    cin >> score;
    node *a=new node;
    a->score=score;
    if(n->next==NULL){
        n->next=a;
        a->next=NULL;
    }
    else
    {
        a->next=n->next;
        n->next=a;
    }
}

void showlist(node *n){
    node *p=n->next;
    while(p!=NULL){
        cout << p->score << ' ';
        p=p->next;
    }
    cout << endl;
}

double fun(list *root){
    int max=0;
    node *p=root->next;
    while(p!=NULL){
        if(max<p->score)
            max=p->score;
        p=p->next;
    }
    return max;
}
