#include"tree.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

typedef struct TREE_NODE{
    struct TREE_NODE *left;
    struct TREE_NODE *right;
    TREE_TYPE value;
}TreeNode;

static TreeNode *tree;

void insert(TREE_TYPE value){
    TreeNode *current;
    TreeNode **link;

    link=&tree;
    while((current=*link)!=NULL){
        if(value<current->value)
            link=&current->left;
        else{
            assert(value!=current->value);
            link=&current->right;
        }
    }
    current=malloc(sizeof(TreeNode));
    assert(current!=NULL);
    current->value=value;
    current->left=NULL;
    current->right=NULL;
    *link=current;
}
TREE_TYPE *find(TREE_TYPE value){
    TreeNode *current;
    current=tree;
    while(current!=NULL&&current->value!=value){
        if(value<current->value)
            current=current->left;
        else 
            current=current->right;
    }
    if(current!=NULL){
        printf("current:%p\n&current->value:%p\n",current,&current->value);
        //return &current->value;
        return (int*)current;
    }
    else 
        return NULL;
}
static void do_pre_order_traverse(TreeNode *current,void (*callback)(TREE_TYPE value)){
    if(current!=NULL){
        callback(current->value);
        do_pre_order_traverse(current->left,callback);
        do_pre_order_traverse(current->right,callback);
    }
}
void pre_order_traverse(void (*callback)(TREE_TYPE value)){
    do_pre_order_traverse(tree,callback);
}
