struct CELL{
    struct CELL *next;
    int data;
};

struct CELL head, *p;

for(p = head.next; p != &head; p = p->next){
    /*pで指されるセルの処理を行う*/
}

