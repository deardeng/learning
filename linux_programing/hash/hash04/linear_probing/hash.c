#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

typedef enum entry_status{
    EMPTY,
    ACTIVE,
    DELETED
}entry_status_t;

typedef struct hash_node{
    enum entry_status status;
    void *key;
    void *value;
}hash_node_t;

struct hash{
    unsigned int buckets;
    hashfunc_t hash_func;
    hash_node_t *nodes;
};

unsigned int hash_get_bucket(hash_t *hash,void *key);
hash_node_t* hash_get_node_by_key(hash_t *hash,void *key,unsigned int key_size);

hash_t* hash_alloc(unsigned int buckets,hashfunc_t hash_func){
    hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
    hash->buckets = buckets;
    hash->hash_func = hash_func;
    int size = buckets*sizeof(hash_node_t);
    hash->nodes = (hash_node_t *)malloc(size);
    memset(hash->nodes,0,size);
    unsigned int i;
    for(i=1;i<=buckets;i++)
        hash->nodes[i-1].status = EMPTY;
    return hash;
}

void* hash_lookup_entry(hash_t *hash,void* key,unsigned int key_size){
    hash_node_t *node = hash_get_node_by_key(hash,key,key_size);
    if(node == NULL){
        return NULL;
    }
    return node->value;
}

void hash_add_entry(hash_t *hash,void *key,unsigned int key_size,void *value,unsigned int value_size){
    if(hash_lookup_entry(hash,key,key_size)){
        fprintf(stderr,"duplicate hash key\n");
        return ;
    }
    unsigned int bucket = hash_get_bucket(hash,key);
    unsigned int i = bucket;
    while(hash->nodes[i].status == ACTIVE){
        i = (i+1)%hash->buckets;
        if(i == bucket){
            return ;
        }
    }
    hash->nodes[i].status = ACTIVE;
    if(hash->nodes[i].key){
        free(hash->nodes[i].key);
    }
    hash->nodes[i].key = malloc(key_size);
    memcpy(hash->nodes[i].key,key,key_size);
    if(hash->nodes[i].value){
        free(hash->nodes[i].value);
    }
    hash->nodes[i].value = malloc(value_size);
    memcpy(hash->nodes[i].value,value,value_size);
}

void hash_free_entry(hash_t *hash,void *key,unsigned int key_size){
    hash_node_t *node = hash_get_node_by_key(hash,key,key_size);
    if(node == NULL)
        return ;
    node->status = DELETED;
}

unsigned int hash_get_bucket(hash_t *hash,void *key){
    unsigned int bucket = hash->hash_func(hash->buckets,key);
    if(bucket >= hash->buckets){
        fprintf(stderr,"bad bucket lookup\n");
        exit(EXIT_FAILURE);
    }
    return bucket;
}

hash_node_t* hash_get_node_by_key(hash_t *hash,void *key,unsigned int key_size){
    unsigned int bucket = hash_get_bucket(hash,key);
    unsigned int i = bucket;
    //while((hash->nodes[i].status == ACTIVE || hash->nodes[i].status == DELETED) && memcmp(key,hash->nodes[i].key,key_size) != 0){
    while(hash->nodes[i].status != EMPTY && memcmp(key,hash->nodes[i].key,key_size) != 0){
        i = (i+1)%hash->buckets;
        if(i == bucket)
            return NULL;
    }
    if(hash->nodes[i].status == ACTIVE)
        return &(hash->nodes[i]);
    return NULL;
}
