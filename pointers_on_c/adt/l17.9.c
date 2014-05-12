#include"tree.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0
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

void print(TREE_TYPE value){
    printf("<%d>",value);
}

int count_nodes(TreeNode *tree){
    if(tree==NULL)
        return 0;
    return 1+count_nodes(tree->left)+count_nodes(tree->right);
}
void printu(TreeNode *t,int space,char sign){
    if(t==NULL)return;
    int i;
    printu(t->right,space+3,'/');
    for(i=0;i<space;i++)
        printf(" ");
    printf("%c%d\n",sign,t->value);
    printu(t->left,space+3,'\\');
}

int check_bst_subtree(TreeNode *node,int min,int max){
    if(node==NULL)
        return TRUE;

    if(node->value<min||node->value>max)
        return FALSE;

    if(!check_bst_subtree(node->left,min,node->value-1)||!check_bst_subtree(node->right,node->value+1,max))
        return FALSE;
    return TRUE;
}
int check_bst_tree(){
    return check_bst_subtree(tree,INT_MIN,INT_MAX);
}

static void do_destroy_tree(TreeNode *current){
    if(current!=NULL){
        do_destroy_tree(current->left);
        do_destroy_tree(current->right);
        free(current);
    }
    current=NULL;
}
void destroy_tree(){
    do_destroy_tree(tree);
    tree=NULL;//I add to call count_nodes
}
//that's myself to change the function,which don't need to add "tree=NULL;" to call count_nodes.it can change the pointer tree to NULL.
//
//
//static void do_destroy_tree(TreeNode **current){
//    if(*current!=NULL){
//        do_destroy_tree(&(*current)->left);
//        do_destroy_tree(&(*current)->right);
//        free(*current);
//    }
//    *current=NULL;
//}
//void destroy_tree(){
//    do_destroy_tree(&tree);
//}

void delete(TREE_TYPE value){
    TreeNode *current;
    TreeNode **link;

    link=&tree;
    //First,locate the value.It must exist in the tree or this routine will abort the program.

    while((current=*link)!=NULL&&value!=current->value){
        if(value<current->value)
            link=&current->left;
        else 
            link=&current->right;
    }
    assert(current!=NULL);
    //We've found the value.See how many children it has.

    if(current->left==NULL&&current->right==NULL){
        //It is a leaf;no children to worry about!
        *link=NULL;
        free(current);
    }
    else if(current->left==NULL||current->right==NULL){
        //The node has only one child,so the parent will simply inherit it.
        if(current->left!=NULL)
            *link=current->left;
        else 
            *link=current->right;
        free(current);
    }
    else{
        //The node has two children!Replace its value with the largest value from its left subtree,and then delete that node instead.
        TreeNode *this_child;
        TreeNode *next_child;

        this_child=current->left;
        next_child=this_child->right;
        while(next_child!=NULL){
            this_child=next_child;
            next_child=this_child->right;
        }
        //Delete the child and replace the current value with this_child's value.
        value=this_child->value;
        delete(value);
        current->value=value;
    }
}

int main(){
    int *p;
    insert(1);
    insert(2);
    insert(20);
    insert(22);
    insert(21);
    insert(13);
    insert(18);
    insert(3);
    insert(5);
    pre_order_traverse(print);
    printf("\n");
    p=find(20);
    printf("%p\n",p);
    p=find(100);
    printf("%p\n",p);
    printf("The tree nodes are :%d\n",count_nodes(tree));
    printu(tree,0,'*');
    printf("The tree is bst?");
    check_bst_tree()?putchar('Y'):putchar('N');
    delete(13);
    //delete(199);//assert();will abort the program.
    printu(tree,0,'*');
    check_bst_tree()?putchar('Y'):putchar('N');
    putchar('\n');
    destroy_tree();
    printf("after destroy_tree the tree nodes are :%d\n",count_nodes(tree));
    printu(tree,0,'*');
    return 0;
}
