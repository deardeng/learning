void add_new_trans(Node *list,Node **current,Transaction *trans);
void delete_trans(Node *list,Node **current,Transaction *trans);
void search(Node *list,Node **current,Transaction *trans);
void edit(Node *list,Node **current,Transaction *trans);

void forward(Node *list,Node **current,Transaction *trans){
    *current=(*current)->next;
}
void backward(Node *list,Node **current,Transaction *trans){
    *current=(*current)->prev;
}

void (*function[])(Node *list,Node **current,Transaction *trans)={
    add_new_trans,
    delete_trans,
    forward,
    backward,
    search,
    edit
};

#define N_TRANSACTIONS (sizeof(function)/sizeof(function[0]))

if(Transaction->type<0||transaction_type>=N_TRANSACTIONS)
    printf("Illegal transaction type!\en");
else
    function[transaction->type](list,&current,transaction);
