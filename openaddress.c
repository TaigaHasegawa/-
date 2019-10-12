#define BUCKET_SIZE 70
typedef int KEY;
typedef float DATA;

#define EMPTY (KEY)0
#define DELETED (KEY)1

typedef struct bucket{
    KEY key;
    DATA data;
} BUCKET;
BUCKET table[BUCKET_SIZE];

int rehash(int h){
    return (h+1)%BUCKET_SIZE;
}

void init(){
    int i;
    for(i=0; i<BUCKET_SIZE; i++){
        table[i].key = EMPTY;
    }
}

DATA *find(KEY key){
    int h, count;
    KEY k;
    count = 0;
    h = hash(key);
    while((k = table[h].key)!=EMPTY){
        if(k!=DELETED && keyequal(key, k))
            return &table[h].data;
        if(++count > BUCKET_SIZE)
            return NULL;
        h = rehash(h);
    }
}

int insert(KEY key, DATA *data){
    int h, count;
    KEY k;

    count = 0;
    h = hash(key);
    while((k = table[h].key) != EMPTY && k!= DELETED){
        if(keyequal(key, k))
            return 0;
        if(++count > BUCKET_SIZE){
            fprintf(stderr, "hash table overflow\n");
            exit(1);
        }
        h = rehash(h);
    }
    table[h].key = key;
    table[h].data = *data;
    return 1;
}

int delete(KEY key){
    int h,count;
    KEY k;

    count = 0;
    h = hash(key);
    while((k=table[h].key)!=EMPTY){
        if(k!=DELETED && keyequal(key,k)){
            table[h].key = DELETED;
            return 1;
        }
        if(++count > BUCKET_SIZE)
            return 0;
        h = rehash(h);
    }
    return 0;
}