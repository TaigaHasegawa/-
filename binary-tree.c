struct node{
    struct node *left;
    struct node *right;
    char label;
};

void preorder(struct node *p){
    if(p==NULL)
        return;
    printf("節%cに立ち寄りました\n", p->label);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p){
    if(p==NULL)
        return;
    inorder(p->left);
    printf("節%cに立ち寄りました\n",p->label);
    inorder(p->right);
}

void postorder(struct node *p){
    if(p==NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("節%cに立ち寄りました\n",p->label);
}