typedef int KEY; 

typedef struct node{
    KEY data;
    struct node *left, *right;
} NODE;

int keyequal(KEY a, KEY b);
int keylt(KEY a, KEY b);

NODE *root = NULL;

NODE *search(KEY key){
    NODE  *p;
    p = root;
    while(p != NULL){
        if (keyequal(key, p->data))
            return p;
        else if(keylt(key, p->data))
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

NODE *insert(KEY key){
    NODE **p, *new;
    p = &root;
    while(*p != NULL){
        if(keyequal(key, (*p)->data))
            return NULL;
        else if (keylt(key, (*p)->data))
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }
    if ((new = malloc(sizeof(NODE)))==NULL)
        error("out of memory!!");
    new->left = NULL;
    new->right = NULL;
    new->data = key;
    *p = new;
    return new;
}

int delete(KEY key){
    NODE **p, *x;
    p = &root;
    while(*p != NULL){
        if(keyequal(key,(*p)->data)){
            x = *p;
            if(x->left == NULL && x->right == NULL)
                *p = NULL;
            else if (x->left == NULL)
                *p = x->right;
            else if (x->right == NULL)
                *p = x->left;
            else{
                *p = deletemin(&x->right);
                (*p)->right = x->right;
                (*p)->left = x->left;
            }
            free(x);
            return 1;
        }else if(keylt(key, (*p)->data))
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }
    return 0;
}


NODE *deletemin(NODE **p){
    NODE *x;
    while((*p)->left != NULL)
        p = &(*p)->left;
    x = *p;
    *p = (*p)->right;
    return x;
}
