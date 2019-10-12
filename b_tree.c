#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHILD 5
#define HALF_CHILD ((MAX_CHILD+1)/2)

typedef int KEY;
typedef int DATA;

typedef struct node{
    int nodekind;
    union{
        struct{
            int _nchilds;
            struct node *_child[MAX_CHILD];
            KEY _low[MAX_CHILD];
        } _internel;
        struct{
            KEY _leaf_key;
            DATA _your_data;
        } _leaf;
    } _u;
} NODE;

#define INTERNEL 1
#define LEAF 2

#define nchilds _u._internel._nchilds
#define child _u._internel._child
#define low _u._internel._low

#define leaf_key _u._leaf._leaf_key
#define your_data _u._leaf._your_data

NODE *root = NULL;

error(char *s){
    fprintf(stderr, s);
    exit(1);
}

NODE *alloc_node(void){
    NODE *p;
    if((p = malloc(sizeof(NODE))) == NULL)
        error("メモリを使い果たしました\n");
    return p;
}

