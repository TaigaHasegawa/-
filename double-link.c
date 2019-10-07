struct CELL {
    struct CELL *prev;
    struct CELL *next;
    int value;
};

struct CELL *p, *x;
struct CELL head;

void insert(){
    x->prev = p;
    x->next = p ->next;
    p -> next -> prev = x;
    p -> next = x;
}

void delete(){
    if (p==&head)
        error("リストの頭は削除できません");
    p->prev->next = p->next;
    p->next->prev = p->prev;
}