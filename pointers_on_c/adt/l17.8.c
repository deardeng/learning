#include<stdio.h>
#include<assert.h>
#include"tree.h"

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE+1)

static TREE_TYPE tree[ARRAY_SIZE];

static int left_child(int current){
    return current*2;
}
static int right_child(int current){
    return current*2+1;
}
void insert(TREE_TYPE value){
    int current;
    assert(value!=0);
    current=1;
    while(tree[current]!=0){
        if(value<tree[current])
            current=left_child(current);
        else{
            assert(value!=tree[current]);
            current=right_child(current);
        }
        assert(current<ARRAY_SIZE);
    }
    tree[current]=value;
}
TREE_TYPE *find(TREE_TYPE value){
    int current;
    current=1;
    while(current<ARRAY_SIZE&&tree[current]!=value){
        if(value<tree[current])
            current=left_child(current);
        else 
            current=right_child(current);
    }
    if(current<ARRAY_SIZE)
        return tree+current;
    else 
        return 0;
}
static void do_pre_order_traverse(int current,void (*callback)(TREE_TYPE value)){
    if(current<ARRAY_SIZE&&tree[current]!=0){
        callback(tree[current]);
        do_pre_order_traverse(left_child(current),callback);
        do_pre_order_traverse(right_child(current),callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value)){
    do_pre_order_traverse(1,callback);
}

void delete(TREE_TYPE value){
    int current,left,right,left_subtree_empty,right_subtree_empty;

    current=1;
    while(tree[current]!=value){
        if(value<tree[current])
            current=left_child(current);
        else 
            current=right_child(current);
        assert(current<ARRAY_SIZE);
        assert(tree[current]!=0);
    }

    left=left_child(current);
    right=right_child(current);
    left_subtree_empty=left>ARRAY_SIZE||tree[left]==0;
    right_subtree_empty=right>ARRAY_SIZE||tree[right]==0;

    if(left_subtree_empty&&right_subtree_empty)
        tree[current]=0;
    else{
        int this_child;
        int next_child;

        if(!left_subtree_empty){
            this_child=left;
            next_child=right_child(this_child);

            while(next_child<ARRAY_SIZE&&tree[next_child]!=0){
                this_child=next_child;
                next_child=right_child(this_child);
            }
        }
        else{
            this_child=right;
            next_child=left_child(this_child);

            while(next_child<ARRAY_SIZE&&tree[next_child]!=0){
                this_child=next_child;
                next_child=left_child(this_child);
            }
        }
        value=tree[this_child];
        delete(value);
        tree[current]=value;
    }
}

