#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

typedef enum entry_status{
    EMPTY,
    ACTIVE,
    DELETED
} entry_status_t;

typedef struct hash_node{
    enum entry_status status;
    void *key;
    unsigned int key_size;
    void *value;
    unsigned int value_size;
}hash_node_t;

struct hash{
    unsigned int buckets;
    unsigned int size;
    hashfunc_t hash_func;
    hash_node_t *nodes;
};

unsigned int next_prime(unsigned int n);
int is_prime(unsigned int n);

unsigned int hash_get_bucket(hash_t *hash,void *key);
hash_node_t* hash_get_node_by_key(hash_t *hash,void *key,unsigned int key_size);

hash_t* hash_alloc(unsigned int buckets,hashfunc_t hash_func){
    hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
    hash->buckets = buckets;
    hash->hash_func = hash_func;
    int size = buckets*sizeof(hash_node_t);
    hash->nodes = (hash_node_t *)malloc(size);
    memset(hash->nodes,0,size);
    return hash;
}

void* hash_lookup_entry(hash_t *hash,void *key,unsigned int key_size){
    hash_node_t* node = hash_get_node_by_key(hash,key,key_size);
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
    unsigned int i =  bucket;

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

    if(++(hash->size) < hash->buckets/2)
        return ;

    unsigned int old_buckets = hash->buckets;
    hash->buckets = next_prime(2*old_buckets);
    hash_node_t *p = hash->nodes;
    unsigned int size;
    hash->size = 0;
    size = sizeof(hash_node_t)*hash->buckets;
    hash->nodes = (hash_node_t *)malloc(size);
    memset(hash->nodes,0,size);
    for(i=0;i<old_buckets;i++){
        if(p[i].status == ACTIVE){
            hash_add_entry(hash,p[i].key,p[i].key_size,p[i].value,p[i].value_size);
        }
    }
    for(i=0;i<old_buckets;i++){
        if(p[i].key){
            free(p[i].key);
        }
        if(p[i].value){
            free(p[i].value);
        }
    }
    free(p);
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
    unsigned int i = 0;
    unsigned int pos = bucket;
    int odd = 1;
    while(hash->nodes[pos].status != EMPTY && memcmp(key,hash->nodes[pos].key,key_size) != 0){
        if(odd){
            pos += 2*++i-1;;
            odd =0;
            while(pos >= hash->buckets)
                pos -= hash->buckets;
        }
        else{
            pos -= 2*i-1;
            odd =1;
            while(pos <0)
                pos += hash->buckets;
        }
    }
    if(hash->nodes[pos].status == ACTIVE)
        return &(hash->nodes[pos]);


    return NULL;
}

unsigned int next_prime(unsigned int n){
    if(n%2 == 0)
        n++;
    for(;!is_prime(n);n+=2);
    return n;
}

int is_prime(unsigned int n){
    unsigned int i;
    for(i=3;i*i<=n;i+=2){
        if(n%i == 0)
            return 0;
    }
    return 1;
}
