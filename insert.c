struct CELL {
    struct CELL *next;
    int value;
} header;

insert(int a){
    struct CELL *p, *q, *new;
    p = header.next;
    q = &header;
    while(p!=NULL && a>p->value)
    {
        q = p;
        p = p->next;
    }
    if ((new=malloc(sizeof(struct CELL)))==NULL){
        fatal_error("メモリが足りません");
    }
    new -> next = p;
    new -> value = a;
    q -> next = new;
}