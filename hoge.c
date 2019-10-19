
typedef struct node{
    int key;
    struct Node *prev, *next;
}Node;

typedef struct list{
    struct Node *head, *tail;
}List;

Node *search(List *L, int key){
    Node *node = L->head;
    while(node->key != key && node != NULL){
        node = node->next;
    }
    return node;
}

void insert(List *L, Node *x){
    Node *old = L->head;
    x ->next = old;
    old->prev = x;
    L->head = x;
}

void reverse(List *L){
    Node *t, *s;
    t = L->head;
    L-> head = L->tail;
    L-> tail = t;
    while(t != NULL){
        s = t->next;
        t->next = t->prev;
        t->prev = s;
        t = s;
    }
}

