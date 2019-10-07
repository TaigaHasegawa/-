#define MAX_GAKUSEI 2000
#define MAX_KAMOKU 400

struct SEISEKI {
    struct SEISEKI *glink;
    struct SEISEKI *klink;
    struct GAKUSEI *gakusei;
    struct KAMOKU *kamoku;
    short seiseki;
};

struct GAKUSEI{
    struct SEISEKI *glink;
    char *name;
}gakusei[MAX_GAKUSEI];

struct KAMOKU{
    struct SEISEKI *klink;
    char *name;
}kamoku[MAX_KAMOKU];

void initialize(){
    int i;
    for(i=0; i<MAX_GAKUSEI; i++)
        gakusei[i].glink = NULL;
    for(i=0; i<MAX_KAMOKU; i++)
        kamoku[i].klink = NULL;
}

void add (int x, int y, short a){
    struct SEISEKI *p;
    if((p=malloc(sizeof(struct SEISEKI)))==NULL)
        error("メモリが足りません");
    p -> glink = gakusei[x].glink;
    gakusei[x].glink = p;
    p -> klink = kamoku[y].klink;
    kamoku[y].klink = p;
    p -> gakusei = &gakusei[x];
    p -> kamoku = &kamoku[y];
    p -> seiseki = a;
}

short get_seiseki(int x, int y){
    struct SEISEKI *p;
    for(p = gakusei[x].glink; p!=NULL; p = p->glink)
        if (p->kamoku == &kamoku[y])
            return (p->seiseki);
    return -1;
}

void print_gakusei(int x){
    struct SEISEKI *p;
    for(p = kamoku[x].klink; p!=NULL; p=p->klink)
        printf("%s %d\n", p->gakusei->name, p->seiseki);
}
